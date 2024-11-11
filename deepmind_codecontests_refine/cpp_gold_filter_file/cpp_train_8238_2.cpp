#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 3e5 + 5;
long long a[maxn];
long long dp[maxn][3];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int q = 1; q <= n; q++) scanf("%lld", &a[q]);
  for (int q = 1; q <= n; q++) {
    dp[q][0] = max(dp[q - 1][0], 0ll) + a[q];
    dp[q][1] = max(max(dp[q - 1][0], dp[q - 1][1]), 0ll) + a[q] * x;
    dp[q][2] = max(max(dp[q - 1][2], dp[q - 1][1]), 0ll) + a[q];
  }
  long long ans = 0;
  for (int q = 1; q <= n; q++) {
    ans = max(ans, dp[q][0]);
    ans = max(ans, dp[q][1]);
    ans = max(ans, dp[q][2]);
  }
  printf("%lld\n", ans);
  return 0;
}
