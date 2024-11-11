#include <bits/stdc++.h>
using namespace std;
int a[205], p[205], n, m, l;
double f[205][205][205 + 205];
void work() {
  int i, j, k;
  cin >> n >> l >> m;
  for (i = 1; i <= n; ++i) cin >> p[i];
  for (i = 1; i <= n; ++i) cin >> a[i];
  f[0][0][m + n] = 1;
  for (i = 0; i < n; ++i)
    for (j = 0; j <= n; ++j)
      for (k = -n; k <= n; ++k)
        if (f[i][j][k + n] != 0) {
          f[i + 1][j][k + n] += f[i][j][k + n] * (100 - p[i + 1]) / 100;
          f[i + 1][j + 1][min(k + a[i + 1], n) + n] +=
              f[i][j][k + n] * p[i + 1] / 100;
        }
  double ans = 0;
  for (k = l; k <= n; ++k)
    for (j = 0; j <= n; ++j) ans += f[n][k][j + n];
  printf("%.9lf", ans);
}
int main() {
  work();
  return 0;
}
