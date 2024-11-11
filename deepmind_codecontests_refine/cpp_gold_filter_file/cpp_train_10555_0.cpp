#include <bits/stdc++.h>
using namespace std;
long long dp[305][305], g[305][305];
int main() {
  int n, m, K, l, r, c;
  cin >> n >> m >> K;
  memset(dp, 0x3f, sizeof(dp));
  memset(g, 0x3f, sizeof(g));
  for (int i = 0; i <= n; ++i) dp[i][0] = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &l, &r, &c);
    for (int j = l; j <= r; ++j) g[j][r] = min(g[j][r], c + 0LL);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
    for (int j = 1; j <= i; ++j)
      for (int k = 1; k <= i; ++k)
        dp[i][j] = min(dp[i][j], dp[k - 1][j - (i - k + 1)] + g[k][i]);
    for (int j = n; j >= 1; --j) dp[i][j] = min(dp[i][j], dp[i][j + 1]);
  }
  if (dp[n][K] == 0x3f3f3f3f3f3f3f3fLL)
    puts("-1");
  else
    printf("%I64d\n", dp[n][K]);
  return 0;
}
