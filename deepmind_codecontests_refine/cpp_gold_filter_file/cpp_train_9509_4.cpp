#include <bits/stdc++.h>
int dp[2][1005];
int main() {
  char start[2 * 1005], end[1005];
  int i, j, k, K;
  while (scanf("%s %s %d", start, end, &K) != EOF) {
    memset(dp, 0, sizeof(dp));
    int n = strlen(start);
    for (i = n; i < 2 * n; i++) start[i] = start[i - n];
    dp[0][0] = 1;
    int cur = 1;
    long long sum[2];
    sum[0] = 1, sum[1] = 0;
    for (k = 0; k < K; k++) {
      sum[cur] = 0;
      for (i = 0; i < n; i++) {
        dp[cur][i] = (sum[cur ^ 1] - dp[cur ^ 1][i] + 1000000007);
        if (dp[cur][i] >= 1000000007) dp[cur][i] -= 1000000007;
        sum[cur] = (sum[cur] + dp[cur][i]);
        if (sum[cur] >= 1000000007) sum[cur] -= 1000000007;
      }
      cur ^= 1;
    }
    int ans = 0;
    for (i = 0; i < n; i++)
      if (strncmp(start + i, end, n) == 0)
        ans += dp[cur ^ 1][i], ans %= 1000000007;
    printf("%d\n", ans);
  }
}
