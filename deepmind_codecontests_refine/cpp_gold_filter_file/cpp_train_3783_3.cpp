#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return d > eps ? 1 : -1;
}
int a[600][600], sum[600][600], n, m;
inline int getsum(int x0, int y0, int x2, int y2) {
  return sum[x2][y2] - sum[x0 - 1][y2] - sum[x2][y0 - 1] + sum[x0 - 1][y0 - 1];
}
int dp[2][511][511];
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  memset((a), 0, sizeof(a));
  memset((sum), 0, sizeof(sum));
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      if (i == 1 && j == 1) {
        sum[i][j] = a[i][j];
      } else if (j == 1) {
        sum[i][j] = a[i][j] + sum[i - 1][j];
      } else if (i == 1) {
        sum[i][j] = a[i][j] + sum[i][j - 1];
      } else {
        sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      }
    }
  }
  int ans = INT_MIN;
  memset((dp), 0, sizeof(dp));
  for (i = 1; i <= n - 2; i++) {
    for (j = 1; j <= m - 2; j++) {
      int t = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2] +
              a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];
      dp[0][i][j] = t;
      ans = max(ans, t);
    }
  }
  int p1 = 0, p2 = 1;
  for (k = 5; k <= min(n, m); k += 2) {
    memset((dp[p2]), 0, sizeof(dp[p2]));
    for (i = 1; i + k - 1 <= n; i++) {
      for (j = 1; j + k - 1 <= m; j++) {
        int ts = getsum(i, j, i + k - 1, j + k - 1);
        ts -= a[i + 1][j];
        int r = dp[p1][i + 1][j + 1];
        dp[p2][i][j] = ts - r;
        ans = max(ans, ts - r);
      }
    }
    swap(p1, p2);
  }
  printf("%d\n", ans);
  return 0;
}
