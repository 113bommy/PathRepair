#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7;
int n;
long long a[N];
long long r1, r2, r3, d;
long long dp[N][2];
int main() {
  scanf("%d %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  dp[1][0] = a[1] * r1 + r3;
  dp[1][1] = min(r2, (a[1] + 1) * r1);
  for (int i = 2; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][1] + 2 * d + a[i] * r1 + r3,
                   dp[i - 1][0] + a[i] * r1 + r3) +
               d;
    dp[i][0] = min(
        dp[i][0], dp[i - 1][1] + 2 * r1 + 2 * d + min((a[i] + 1) * r1, r2) + d);
    dp[i][1] = min(dp[i - 1][0] + min((a[i] + 1) * r1, r2),
                   dp[i - 1][1] + 2 * d + r1 + min((a[i] + 1) * r1, r2)) +
               d;
  }
  long long ans = min(dp[n][0], dp[n - 1][1] + 2 * d + r1 + a[n] * r1 + r3);
  printf("%lld\n", ans);
  return 0;
}
