#include <bits/stdc++.h>
int main() {
  char tab[8][8];
  int flag = 0;
  int x, i, j;
  int bestW = 0;
  int bestB = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      scanf(" %c", &tab[i][j]);
    }
  }
  for (i = 1; i < 8; i++) {
    for (j = 1; j < 8; j++) {
      if (tab[i][j] == 'W') {
        for (x = i - 1; x >= 0; x--) {
          if (tab[x][j] != '.') {
            break;
          }
        }
        if (x == -1) flag = 1;
        if (flag == 1) {
          bestW = i;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1) break;
  }
  flag = 0;
  for (i = 7; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      if (tab[i][j] == 'B') {
        for (x = i + 1; x <= 7; x++) {
          if (tab[x][j] != '.') {
            break;
          }
        }
        if (x == 8) flag = 1;
        if (flag == 1) {
          bestB = 7 - i;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1) break;
  }
  if (bestW <= bestB)
    printf("A");
  else
    printf("B");
  return 0;
}
