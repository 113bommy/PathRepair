#include <bits/stdc++.h>
int main() {
  char grid[9][9];
  int row[9], col[9], mCount, flag;
  mCount = 0;
  memset(row, 0, sizeof row);
  memset(col, 0, sizeof col);
  for (int i = 0; i < 8; i++) scanf("%s", grid[i]);
  for (int i = 0; i < 8; i++) {
    flag = 0;
    if (grid[i][0] == 'B') {
      for (int j = 0; j < 8; j++) {
        if (grid[i][j] == 'W') {
          flag = 1;
          break;
        }
      }
      if (flag == 0) row[i] = 1;
    }
  }
  for (int i = 0; i < 8; i++) {
    flag = 0;
    if (grid[0][i] == 'B') {
      for (int j = 0; j < 8; j++) {
        if (grid[j][i] == 'W') {
          flag = 1;
          break;
        }
      }
      if (flag == 0) col[i] = 1;
    }
  }
  for (int i = 0; i < 8; i++) {
    if (row[i] == 1) mCount++;
    if (col[i] == 1) mCount++;
  }
  if (mCount < 16)
    printf("%d\n", mCount);
  else {
    mCount = 8;
    printf("%d\n", mCount);
  }
}
