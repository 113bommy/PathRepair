#include <bits/stdc++.h>
char a[10][10];
int main() {
  char ch;
  int r, c, m = 0, i, j, x;
  scanf("%d%d", &r, &c);
  scanf("%c", &ch);
  for (i = 0; i < r; i++)
    for (j = 0; j <= r; j++) scanf("%c", &a[i][j]);
  for (i = 0; i < r; i++) {
    x = 0;
    for (j = 0; j < c; j++) {
      if (a[i][j] == (int)'S') {
        x = 1;
        break;
      }
    }
    if (x == 0) {
      for (j = 0; j < c; j++) a[i][j] = (int)'y';
    }
  }
  for (i = 0; i < c; i++) {
    x = 0;
    for (j = 0; j < r; j++) {
      if (a[j][i] == (int)'S') {
        x = 1;
        break;
      }
    }
    if (x == 0) {
      for (j = 0; j < r; j++)
        if (a[j][i] != (int)'y') a[j][i] = (int)'y';
    }
  }
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      if (a[i][j] == (int)'y') m++;
  printf("%d", m);
  return 0;
}
