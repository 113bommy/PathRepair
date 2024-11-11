#include <bits/stdc++.h>
int n, m;
long long A[30], B[30];
long long dp[1 << 25], sum[30];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", A + i);
  B[0] = B[1] = -1;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%lld", B + i);
  sum[0] = 0;
  for (int i = 1; i < (1 << n); i++) {
    int j = __builtin_ctz(i);
    sum[i] = sum[(1 << j) ^ i] + A[j];
  }
  dp[0] = 1;
  for (int i = 1; i < (1 << n); i++) {
    if (sum[i] == B[0] || sum[i] == B[1])
      dp[i] = 0;
    else
      for (int j = 0; j < n; j++)
        if ((1 << j) & i) dp[i] += dp[(1 << j) ^ i];
    dp[i] %= 1000000007;
  }
  printf("%lld", dp[(1 << n) - 1]);
}
