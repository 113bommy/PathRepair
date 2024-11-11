#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 9;
const int inf = 1e9 + 9;
const int N = 1e2 + 9;
int n, m, t[N], pre[N][N], suf[N][N], a[N][N], dp[N][N], dp2[N][N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    for (int j = 1; j <= t[i]; j++) {
      scanf("%d", &a[i][j]);
      pre[i][j] = pre[i][j - 1] + a[i][j];
    }
    for (int j = t[i]; j >= 1; j--) {
      suf[i][j] = suf[i][j + 1] + a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t[i]; j++) {
      for (int k = 1; k <= t[i]; k++) {
        for (int tt = t[i]; tt >= 1; tt--) {
          if (k == j) {
            dp2[i][j] = max(dp2[i][j], pre[i][k]);
          }
          if (t[i] - tt + 1 == j) {
            dp2[i][j] = max(dp2[i][j], suf[i][tt]);
          }
          if (k + (t[i] - tt + 1) == j) {
            dp2[i][j] = max(dp2[i][j], pre[i][k] + suf[i][tt]);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t[i]; j++) {
      for (int tt = 1; tt <= m; tt++) {
        if (tt - j < 0) {
          continue;
        }
        dp[i][tt] =
            max(dp[i][tt], max(dp[i - 1][tt], dp[i - 1][tt - j] + dp2[i][j]));
      }
    }
  }
  printf("%d\n", dp[n][m]);
  return 0;
}
