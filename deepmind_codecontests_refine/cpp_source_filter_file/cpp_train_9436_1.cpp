#include <bits/stdc++.h>
int a[6][6];
int main() {
  a[0][0] = 3;
  a[0][1] = 3;
  a[0][2] = 4;
  a[0][3] = 4;
  a[0][4] = 3;
  a[0][5] = 3;
  for (int j = 0; j < 5; j++) a[1][j] = a[1][j];
  for (int j = 0; j < 5; j++) a[2][j] = a[2 - 1][j] - 1;
  for (int j = 0; j < 5; j++) a[3][j] = a[2][j];
  for (int j = 0; j < 5; j++) a[4][j] = a[4 - 1][j] - 1;
  for (int j = 0; j < 5; j++) a[5][j] = a[5 - 1][j];
  char c[6][6];
  for (int i = 0; i < 6; i++) {
    char t;
    scanf("%c%c-%c%c-%c%c\n", &c[i][0], &c[i][1], &c[i][2], &c[i][3], &c[i][4],
          &c[i][5]);
  }
  int max = 0, ii, jj;
  for (int i = 0; i < 6; i++) {
    int flag = 0, flag1 = 0;
    for (int j = 0; j < 5; j++) {
      if (c[i][j] != '*')
        if (a[i][j] > max) {
          max = a[i][j];
          ii = i, jj = j;
        }
    }
  }
  c[ii][jj] = 'P';
  for (int i = 0; i < 6; i++)
    printf("%c%c-%c%c-%c%c\n", c[i][0], c[i][1], c[i][2], c[i][3], c[i][4],
           c[i][5]);
}
