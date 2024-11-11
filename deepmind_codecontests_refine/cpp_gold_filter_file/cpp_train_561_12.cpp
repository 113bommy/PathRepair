#include <bits/stdc++.h>
char a[506][506];
int w;
void f(int x, int y) {
  if (!w) return;
  a[x][y] = '.';
  w++;
  if (a[x][y + 1] == 'X') f(x, y + 1);
  if (a[x + 1][y] == 'X') f(x + 1, y);
  if (a[x][y - 1] == 'X') f(x, y - 1);
  if (a[x - 1][y] == 'X') f(x - 1, y);
}
int main() {
  int i, j, m, n, x, y;
  scanf("%d %d %d", &m, &n, &w);
  for (i = 0; i < m; i++) scanf("%s", a[i]);
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      if (a[i][j] == '.') {
        a[i][j] = 'X';
        x = i;
        y = j;
        w--;
      }
  f(x, y);
  for (i = 0; i < m; i++) printf("%s\n", a[i]);
  return 0;
}
