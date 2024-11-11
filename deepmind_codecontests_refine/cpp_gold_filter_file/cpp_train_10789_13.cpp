#include <bits/stdc++.h>
using namespace std;
long long w, b, x, cost[1005], dp[1005][1005 * 10], sum, n, c[1005];
int main() {
  scanf("%lld %lld %lld %lld", &n, &w, &b, &x);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &cost[i]);
  memset(dp, -1, sizeof dp);
  dp[0][0] = w;
  for (int i = 1; i <= n; i++) {
    sum += c[i];
    for (int j = 0; j <= sum; j++) {
      for (int k = 0; k <= c[i] && k <= j; k++) {
        if (dp[i - 1][j - k] == -1) continue;
        if (dp[i - 1][j - k] - cost[i] * k < 0) continue;
        dp[i][j] =
            max(dp[i][j], min(dp[i - 1][j - k] - cost[i] * k + x, w + j * b));
      }
    }
  }
  for (int i = sum; i >= 0; i--) {
    if (dp[n][i] != -1) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}
