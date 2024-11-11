#include <bits/stdc++.h>
char chess[10][10];
int judge(int row, int col, int dir) {
  int i;
  if (dir == 1) {
    for (i = row - 1; i >= 0; i--)
      if (chess[i][col] != '.') return 0;
    if (i < 0) return 1;
  } else {
    for (i = row + 1; i < 8; i++)
      if (chess[i][col] != '.') return 0;
    if (i >= 8) return 1;
  }
}
int main() {
  int minb, minw;
  while (gets(chess[0])) {
    minb = 9;
    minw = 9;
    for (int i = 0; i < 7; i++) gets(chess[i + 1]);
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (chess[i][j] == 'W' && judge(i, j, 1)) {
          int temp = i;
          if (temp < minw) minw = temp;
        }
        if (chess[i][j] == 'B' && judge(i, j, 0)) {
          int temp = 8 - i - 1;
          if (temp < minb) minb = temp;
        }
      }
    }
    if (minw < minb)
      printf("A\n");
    else
      printf("B\n");
  }
  return 0;
}
