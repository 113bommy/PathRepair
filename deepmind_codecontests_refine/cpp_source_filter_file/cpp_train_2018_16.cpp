#include <bits/stdc++.h>
using namespace std;
int n, m, a[60];
long double ans, f[60][60], c[60][60], all;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
  all = 1;
  for (int i = 1; i <= n; ++i) all *= m;
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  ans = 1;
  for (int x = 1; x <= n; ++x) {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j <= n; ++j)
        for (int k = 0; j + k <= n && k <= x * a[i + 1]; ++k)
          f[i + 1][j + k] += f[i][j] * c[n - j][k];
    ans += 1.0 - f[m][n] / all;
  }
  printf("%.20Lf\n", ans);
  return 0;
}
