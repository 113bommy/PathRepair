#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
const long long inf = 0x3f3f3f3f;
long long dp[2][maxn];
long long a[maxn];
long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
int main() {
  long long n, r1, r2, r3, d;
  scanf("%lld%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  memset(dp, inf, sizeof(dp));
  dp[0][1] = a[1] * r1 + r3;
  dp[1][1] = min(r1 * (a[1] + 1), r2);
  for (int i = 1; i < n; ++i) {
    dp[1][i + 1] = min(dp[0][i] + min(r1 * (a[i + 1] + 1), r2),
                       dp[1][i] + 2 * d + r1 + min(r1 * (a[i + 1] + 1), r2)) +
                   d;
    dp[0][i + 1] =
        min(dp[0][i] + a[i + 1] * r1 + r3,
            min(dp[1][i] + 2 * d + r1 + a[i + 1] * r1 + r3,
                dp[1][i] + 2 * d + 2 * r1 + min(r2, (a[i + 1] + 1) * r1))) +
        d;
  }
  printf("%lld\n", min(dp[0][n], dp[1][n - 1] + 2 * d + r1 + a[n] * r1 + r3));
  return 0;
}
