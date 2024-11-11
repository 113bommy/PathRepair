#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const long long LINF = 1e17 + 7;
const double Pi = acos(-1.);
const double EPS = 1e-8;
int n, m, a[N][N], s[N][N], f[N][N][N >> 1];
int calc(int x0, int y0, int x1, int y1) {
  return s[x1][y1] + s[x0 - 1][y0 - 1] - s[x1][y0 - 1] - s[x0 - 1][y1];
}
int solve() {
  int ret = -INF;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      f[i][j][0] = a[i][j];
      if (i + 2 <= n && j + 2 <= n) {
        f[i][j][1] = calc(i, j, i + 2, j + 2) - a[i + 1][j] - a[i + 1][j + 1];
        ret = max(ret, f[i][j][1]);
      }
    }
  for (int k = 2; 2 * k + 1 <= min(n, m); ++k) {
    int l = 2 * k;
    for (int i = 1; i + l <= n; ++i)
      for (int j = 1; j + l <= m; ++j) {
        f[i][j][k] = f[i + 2][j + 2][k - 2] + calc(i, j, i + l, j + l) -
                     calc(i + 1, j + 1, i + l - 1, j + l - 1) +
                     a[i + 2][j + 1] - a[i + 1][j];
        ret = max(ret, f[i][j][k]);
      }
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  printf("%d\n", solve());
  return 0;
}
