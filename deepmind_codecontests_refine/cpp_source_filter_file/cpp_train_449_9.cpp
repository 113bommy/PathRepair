#include <bits/stdc++.h>
long long dp[2010];
int t[2010];
long long c[2010];
void solve(int n, int limit) {
  for (int i = 0; i < 2010; i++) dp[i] = 0x7FFFFFFFFFFFF;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = limit; j > 0; j--) {
      if (j - t[i] < 1 && dp[j] > c[i])
        dp[j] = c[i];
      else if (dp[j] > dp[j - t[i] - 1] + c[i]) {
        dp[j] = dp[j - t[i] - 1] + c[i];
      }
    }
  }
}
int main() {
  t[0] = 0;
  c[0] = 0;
  int n;
  while (~scanf("%d", &n)) {
    long long sum = 0;
    int buft = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%I64d", &c[i], &t[i]);
    }
    solve(n, n);
    long long ans = dp[n];
    printf("%I64d\n", ans);
  }
}
