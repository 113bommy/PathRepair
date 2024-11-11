#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const long long mod = 998244353;
long long dp[N][N];
long long qpow(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
  return ans;
}
int main() {
  long long n, m, k;
  scanf("%lld%lld%lld", &n, &m, &k);
  dp[0][0] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= i; j++)
      dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (n - j + 1)) % mod;
  long long ans = 0, ret = qpow(m, mod - 2), mul = ret;
  for (int i = 1; i <= k; i++, mul = mul * ret)
    ans = (ans + mul * dp[k][i]) % mod;
  return 0 * printf("%lld\n", ans);
}
