#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m;
int cnt[2][505][505], dp[505][505], ans;
int solve(int len, int ways) {
  if (len >= m) return 0;
  int lim = min(n, (m - 1) / len);
  memset(dp, 0, sizeof(dp));
  dp[1][1] = ways;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= lim; j++) {
      dp[i][j + 1] += dp[i - 1][j];
      if (dp[i][j + 1] >= MOD) dp[i][j + 1] -= MOD;
      dp[i][1] += dp[i - 1][j];
      if (dp[i][1] >= MOD) dp[i][1] -= MOD;
    }
  }
  long long ret = 0;
  for (int i = 1; i <= lim; i++) ret += dp[n][i];
  return ret % MOD;
}
int main() {
  scanf("%d%d", &n, &m);
  cnt[0][1][1] = 2;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) cnt[i & 1][j][k] = 0;
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        cnt[i & 1][j + 1][max(k, j + 1)] += cnt[1 - i & 1][j][k];
        if (cnt[i & 1][j + 1][max(k, j + 1)] >= MOD)
          cnt[i & 1][j + 1][max(k, j + 1)] -= MOD;
        cnt[i & 1][1][k] += cnt[1 - i & 1][j][k];
        if (cnt[i & 1][1][k] >= MOD) cnt[i & 1][1][k] %= MOD;
      }
  }
  for (int i = 1; i <= n; i++) {
    int ways = 0;
    for (int j = 0; j <= n; j++) {
      ways += cnt[1 - n & 1][j][i];
      if (ways >= MOD) ways -= MOD;
    }
    ans += solve(i, ways);
    if (ans >= MOD) ans -= MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
