#include <bits/stdc++.h>
int main() {
  int n, m, i, j, s;
  char a[15][15];
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", a[i]);
  s = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (a[i][j] == 'W') {
        if (a[i - 1][j] == 'P') {
          s++;
          a[i - 1][j] = '.';
          continue;
        }
        if (a[i + 1][j] == 'P') {
          s++;
          a[i + 1][j] = '.';
          continue;
        }
        if (a[i][j - 1] == 'P') {
          s++;
          a[i][j - 1] = '.';
          continue;
        }
        if (a[i][j + 1] == 'P') {
          s++;
          a[i][j + 1] = '.';
          continue;
        }
      }
  printf("%d", s);
  return 0;
}
