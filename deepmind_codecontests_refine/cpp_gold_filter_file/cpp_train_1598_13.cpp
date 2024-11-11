#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
double dp[205][205][550];
double wp[205];
int pr[205];
int n, l, k;
int main() {
  ios_base::sync_with_stdio(false);
  memset(dp, 0, sizeof(dp));
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) cin >> wp[i];
  for (int i = 0; i < n; i++) cin >> pr[i];
  dp[0][0][n + min(n, k)] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = -n; k <= n; k++) {
        dp[i + 1][j][n + k] += dp[i][j][n + k] * (1 - wp[i] / 100);
        dp[i + 1][j + 1][n + min(k + pr[i], n)] +=
            dp[i][j][n + k] * wp[i] / 100;
      }
  double ans = 0;
  for (int j = l; j <= n + 1; j++)
    for (int k = 0; k <= n; k++) ans += dp[n][j][n + k];
  printf("%.9lf\n", ans);
  return 0;
}
