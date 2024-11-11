#include <bits/stdc++.h>
int board[101][101];
int result[101][101];
int N, M, Q;
void rotation_row(int row) {
  int* arr = board[row];
  int temp = board[row][0];
  for (int i = 0; i < M - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[M - 1] = temp;
}
void rotation_column(int column) {
  int temp = board[0][column];
  for (int i = 0; i < N - 1; i++) {
    board[i][column] = board[i + 1][column];
  }
  board[N - 1][column] = temp;
}
int main() {
  scanf("%d %d %d", &N, &M, &Q);
  int values;
  for (int i = 0; i < N; i++) {
    values = i * 1000;
    for (int j = 0; j < M; j++) {
      board[i][j] = values + j;
    }
  }
  for (int i = 0; i < Q; i++) {
    int T, row, column;
    scanf("%d", &T);
    if (T == 1) {
      scanf("%d", &row);
      rotation_row(row - 1);
    } else if (T == 2) {
      scanf("%d", &column);
      rotation_column(column - 1);
    } else if (T == 3) {
      int r, c, x;
      scanf("%d %d %d", &r, &c, &x);
      int indexs = board[r - 1][c - 1];
      int sR = indexs / 1000;
      int sC = indexs % 1000;
      result[sR][sC] = x;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (j == (M - 1))
        printf("%d", result[i][j]);
      else
        printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  return 0;
}
