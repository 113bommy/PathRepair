#include <bits/stdc++.h>
int main() {
  char cake[10][10];
  int cakec[10][10];
  int c, r, i, cells = 0, j;
  scanf("%d%d", &r, &c);
  for (i = 1; i <= c; i++) cakec[0][i] = r;
  for (i = 0; i < r; i++) cakec[i][0] = c;
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++) scanf(" %c", &cake[i][j]);
  for (i = 0; i < r; i++) {
    for (j = 0; j < c && cake[i][j] != 'S'; j++)
      ;
    if (j >= c) {
      cells += cakec[i][0];
      for (j = 1; j <= c; j++) cakec[0][j]--;
    }
  }
  for (i = 0; i < c; i++) {
    for (j = 0; j < r && cake[j][i] != 'S'; j++)
      ;
    if (j >= r) {
      cells += cakec[0][i + 1];
    }
  }
  printf("%d\n", cells);
  return 0;
}
