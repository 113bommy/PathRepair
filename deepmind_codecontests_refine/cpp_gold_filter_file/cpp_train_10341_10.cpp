#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
long long n, ans;
long long way[1000010], dp[1000010];
signed main() {
  scanf("%lld", &n);
  if (n == 2) return printf("10\n"), 0;
  way[0] = 1;
  for (long long i = 1; i <= n / 2; i++)
    way[i] = (2 * (way[i - 1] + 1) + 1) % mod;
  dp[1] = 0;
  dp[2] = 1;
  ans = 0;
  for (long long i = 3; i <= n; i++)
    if (i % 2 == 0)
      dp[i] = dp[i - 1];
    else
      dp[i] = dp[i - 1] * way[(i + 1) / 2 - 2] % mod;
  for (long long i = 1; i <= n; i++) ans = (ans + dp[i] + dp[i + 1]) % mod;
  ans = (ans * ans % mod + 1) * 2 % mod;
  printf("%lld\n", ans);
  return 0;
}
