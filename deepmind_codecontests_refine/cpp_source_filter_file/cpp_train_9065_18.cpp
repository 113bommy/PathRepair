#include <bits/stdc++.h>
using namespace std;
int n, m, f[1003][1003], lx[1003][1003], ly[1003][1003], sx[1003][1003],
    sy[1003][1003];
char st[1003][1003];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", st[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (st[i][j] == '*') {
        lx[i][j] = max(0, lx[i - 1][j]);
        while (st[i - lx[i][j] - 1][j] == '*' && st[i + lx[i][j] + 1][j] == '*')
          lx[i][j]++;
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (st[i][j] == '*') {
        ly[i][j] = max(0, ly[i][j - 1]);
        while (st[i][j - ly[i][j] - 1] == '*' && st[i][j + ly[i][j] + 1] == '*')
          ly[i][j]++;
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      f[i][j] = min(lx[i][j], ly[i][j]);
      if (f[i][j] > 0) {
        sx[i - f[i][j]][j]++;
        sx[i + f[i][j] + 1][j]--;
        sy[i][j - f[i][j]]++;
        sy[i][j + f[i][j] + 1]--;
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      sx[i][j] += sx[i - 1][j];
      sy[i][j] += sy[i][j - 1];
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (st[i][j] == '*' && sx[i][j] == 0 && sy[i][j] == 0) {
        printf("-1\n");
        return 0;
      }
  int s = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (f[i][j] > 0) s++;
  printf("%d\n", s);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (f[i][j] > 0) printf("%d %d %d\n", i, j, f[i][j]);
}
