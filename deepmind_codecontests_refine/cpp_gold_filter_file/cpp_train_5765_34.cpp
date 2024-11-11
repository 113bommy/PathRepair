#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
double f[1005][1005], dp[1005][1005];
void pt(double x) {
  printf("%.10lf\n", x);
  exit(0);
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &x, &y);
  if (x == n) pt(0);
  if (m == 1) pt((n - x) << 1);
  for (int i = n - 1; i; --i) {
    f[1][1] = 2, f[1][2] = -1, f[1][m + 1] = dp[i + 1][1] + 3;
    for (int j = 2; j < m; ++j)
      f[j][j] = 3, f[j][j - 1] = -1, f[j][j + 1] = -1,
      f[j][m + 1] = dp[i + 1][j] + 4;
    f[m][m] = 2, f[m][m - 1] = -1, f[m][m + 1] = dp[i + 1][m] + 3;
    for (int j = 1; j < m; ++j) {
      double g = f[j + 1][j] / f[j][j];
      f[j + 1][j] = 0, f[j + 1][j + 1] -= f[j][j + 1] * g,
            f[j + 1][m + 1] -= f[j][m + 1] * g;
    }
    for (int j = m; j; j--) {
      dp[i][j] = f[j][m + 1] / f[j][j];
      f[j - 1][m + 1] -= dp[i][j] * f[j - 1][j];
    }
    if (i == x) pt(dp[x][y]);
  }
  return 0;
}
