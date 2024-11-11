#include <bits/stdc++.h>
char tab[200][200];
int brd[200][2];
int n, m;
int mv;
int abs(int a) { return (a < 0) ? -a : a; }
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", tab[i]);
    for (j = 0; j < m and tab[i][j] != 'W'; j++)
      ;
    brd[i][0] = (j < m) ? j : -1;
    for (j = m - 1; j >= 0 and tab[i][j] != 'W'; j--)
      ;
    brd[i][1] = (j >= 0) ? j : m;
  }
  mv = 0;
  for (i = 0, j = 0; i < n; mv++) {
    if (brd[i][0] != -1) {
      mv += (i % 2 == 0) ? abs(brd[i][1] - j) : abs(j - brd[i][0]);
      j = (i % 2 == 0) ? brd[i][1] : brd[i][0];
    }
    if (i == n - 1) {
      mv++;
      i++;
      break;
    }
    i++;
    if (brd[i][0] != -1) {
      mv += (i % 2 == 0) ? abs(brd[i][0] - j) : abs(j - brd[i][1]);
      j = (i % 2 == 0) ? brd[i][0] : brd[i][1];
    }
  }
  for (mv--, i--; i > 0 and brd[i][0] == -1; i--, mv--)
    ;
  printf("%d\n", mv);
  return 0;
}
