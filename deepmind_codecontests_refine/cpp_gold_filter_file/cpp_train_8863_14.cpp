#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const long long mod = 998244353;
long long dp[N * 2][N][2];
long long qpow(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
  return ans;
}
int main() {
  int n, k;
  long long l;
  scanf("%d%d%lld", &n, &k, &l);
  dp[0][0][0] = 1;
  for (int i = 0; i <= n * 2; i++) {
    for (int j = 0; j <= min(i, n); j++) {
      dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][0]) % mod;
      if (j)
        dp[i + 1][j - 1][0] = (dp[i + 1][j - 1][0] + dp[i][j][0] * j) % mod;
      dp[i + 1][j + 1][1] = (dp[i + 1][j + 1][1] + dp[i][j][1]) % mod;
      if (j)
        dp[i + 1][j - 1][1] = (dp[i + 1][j - 1][1] + dp[i][j][1] * j) % mod;
      if (j >= k) dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][0]) % mod;
    }
  }
  long long f_n = 1, f_2n = 1, p = 1;
  for (int i = 1; i <= n; i++) f_n = f_n * i % mod, p = p * 2 % mod;
  for (int i = 1; i <= 2 * n + 1; i++) f_2n = f_2n * i % mod;
  printf("%lld\n", l * dp[2 * n + 1][0][1] % mod * p % mod * f_n % mod *
                       qpow(f_2n, mod - 2) % mod);
  return 0;
}
