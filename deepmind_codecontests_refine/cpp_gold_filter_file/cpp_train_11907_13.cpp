#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010], x, y;
double f[1010][1010], ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) f[i][j] = a[i] > a[j];
  while (m--) {
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; ++i)
      if (i != x && i != y) {
        f[i][x] = f[i][y] = (f[i][x] + f[i][y]) / 2;
        f[x][i] = f[y][i] = (f[x][i] + f[y][i]) / 2;
      }
    f[x][y] = f[y][x] = 0.5;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) ans += f[i][j];
  printf("%.10f\n", ans);
  return 0;
}
