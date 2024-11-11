#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1010];
double f[1010][1010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (a[i] > a[j]) f[i][j] = 1;
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    f[x][y] = f[y][x] = 0.5;
    for (int j = 1; j <= n; ++j) {
      if (j == x || j == y) continue;
      f[j][x] = f[j][y] = (f[j][x] + f[j][y]) / 2.0;
      f[x][j] = f[y][j] = 1 - f[j][x];
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) ans += f[i][j];
  printf("%lf\n", ans);
}
