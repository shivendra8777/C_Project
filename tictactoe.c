#include <stdio.h>

char board[3][3];

void resetBoard() {

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            board[i][j] = '1' + i*3 + j;
}

void printBoard() {

    printf("\n");

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---+---+---\n");
    }
    printf("\n\n");
}

int checkWinner() {

    for (int i=0; i<3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];

    for (int j=0; j<3; j++)
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return board[0][j];

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return 0;
}

int isDraw() {

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;

    return 1;
}

int main() {

    int move, row, col, player = 0;
    char mark;

    resetBoard();

    printf("Tic-Tac-Toe Game (Player 1 = X, Player 2 = O)\n");
    while (1) {

        printBoard();

        mark = (player % 2 == 0) ? 'X' : 'O';
        printf("Player %d [%c], enter position (1-9): ", player%2+1, mark);
        scanf("%d", &move);
        if (move < 1 || move > 9) {

            printf("Invalid move. Try again.\n");
            continue;
        }
        row = (move-1) / 3;
        col = (move-1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already taken. Try again.\n");
            continue;
        }
        board[row][col] = mark;
        if (checkWinner()) {

            printBoard();
            printf("Player %d [%c] wins!\n", player%2+1, mark);
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        player++;
    }
    return 0;
}

