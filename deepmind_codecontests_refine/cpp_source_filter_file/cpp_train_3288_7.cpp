#include <bits/stdc++.h>
const long long inf = 1e18;
long long n, m, x, y, z, ans;
std::bitset<510> dp[65][2][510], pre, X;
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &x, &y, &z);
    dp[0][z][x][y] = 1;
  }
  for (long long i = 1; i <= 60; i++)
    for (long long j = 0; j <= 1; j++)
      for (long long u = 1; u <= n; u++)
        for (long long v = 1; v <= n; v++)
          if (dp[i - 1][j][u][v]) dp[i][j][u] |= dp[i - 1][j ^ 1][v];
  for (long long i = 1; i <= n; i++)
    if (dp[60][0][1][i]) return puts("-1"), 0;
  long long tmp = 0;
  pre[1] = 1;
  for (long long i = 59; i >= 0; i--) {
    X = 0;
    for (long long j = 1; j <= n; j++)
      if (pre[j]) X |= dp[i][tmp][j];
    if (X.count()) {
      pre = X;
      tmp ^= 1;
      ans += (1 << i);
    }
  }
  if (ans > inf) return puts("-1"), 0;
  printf("%lld\n", ans);
}
