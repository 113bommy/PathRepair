#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e13;
const int N = 310;
int n, m, p;
long long val[N][N];
long long dp[N][N];
int main() {
  scanf("%d %d %d", &n, &m, &p);
  memset(val, 0, sizeof(val));
  for (int i = 0, l, r, c; i < m; ++i) {
    scanf("%d %d %d", &l, &r, &c);
    for (int j = l; j <= r; ++j)
      if (!val[j][r] or val[j][r] > c) val[j][r] = c;
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= p; ++j) {
      long long &cur = dp[i][j];
      cur = dp[i - 1][j];
      for (int k = 1; i - k >= 1 && k <= j; ++k)
        if (val[i - k + 1][i] && dp[i - k][j - k] != -1) {
          if (cur == -1)
            cur = dp[i - k][j - k] + val[i - k + 1][i];
          else
            cur = min(cur, dp[i - k][j - k] + val[i - k + 1][i]);
        }
    }
  }
  long long ans = inf;
  for (int i = p; i <= n; ++i)
    if (dp[n][i] != -1) ans = min(ans, dp[n][i]);
  if (ans != inf)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
