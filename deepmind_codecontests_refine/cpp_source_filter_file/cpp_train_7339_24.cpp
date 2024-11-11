#include <bits/stdc++.h>
int main() {
  char board[8][9];
  int minA = 10, minB = 10;
  for (int i = 0; i < 8; i++) scanf("%s", board[i]);
  for (int i = 1; i < 7; i++)
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == 'W') {
        bool flag = true;
        for (int k = i - 1; k >= 0; k--)
          if (board[k][j] != '.') {
            flag = false;
            break;
          }
        if (flag && minA > i) minA = i;
      }
      if (board[i][j] == 'B') {
        bool flag = true;
        for (int k = i + 1; k < 8; k++)
          if (board[k][j] != '.') {
            flag = false;
            break;
          }
        if (flag && minB > 7 - i) minB = 7 - i;
      }
    }
  if (minA < minB)
    printf("A\n");
  else
    printf("B\n");
  return 0;
}
