#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 4001;
int n, l, k;
int dp[2005][2005][2];
long long fir[4005], inv[4005];
int adds(int v) { return (v >= mod) ? v - mod : v; }
long long ksm(long long x, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ans;
}
void pre() {
  fir[0] = 1;
  for (int i = 1; i <= maxn; i++) fir[i] = fir[i - 1] * i % mod;
  inv[maxn] = ksm(fir[maxn], mod - 2) % mod;
  for (int i = maxn - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long C(int n, int m) { return fir[n] * inv[m] % mod * inv[n - m] % mod; }
int main() {
  pre();
  scanf("%d%d%d", &n, &k, &l);
  dp[0][0][0] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      for (int op = 0; op <= 1; op++) {
        if (!dp[i][j][op]) continue;
        if (j < i)
          dp[i][j + 1][op] =
              adds(dp[i][j + 1][op] + dp[i][j][op] * (i - j) % mod);
        if (i < n) dp[i + 1][j][op] = adds(dp[i + 1][j][op] + dp[i][j][op]);
        if (!op && i - j >= k)
          dp[i][j][op + 1] = adds(dp[i][j][op + 1] + dp[i][j][op]);
      }
  long long ans = dp[n][n][1] * ksm(2, n) % mod * fir[n] % mod *
                  inv[2 * n + 1] % mod * l % mod;
  printf("%lld\n", ans);
}
