#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m;
int a[66], w[66];
long long dp[66][66][66];
int sa, sb, sum;
long long inv[10010];
void solve1(int x) {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  long long zi, mu;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= i; ++j)
      for (int k = j; k <= i; ++k) {
        if (!dp[i][j][k]) continue;
        mu = inv[sum + k * 2 - i];
        zi = (w[x] + j) % mod;
        (dp[i + 1][j + 1][k + 1] += dp[i][j][k] * zi % mod * mu % mod) %= mod;
        zi = (sa + k - j - w[x] + mod) % mod;
        (dp[i + 1][j][k + 1] += dp[i][j][k] * zi % mod * mu % mod) %= mod;
        zi = (sb - i + k + mod) % mod;
        (dp[i + 1][j][k] += dp[i][j][k] * zi % mod * mu % mod) %= mod;
      }
  long long r = 0;
  for (int j = 0; j <= m; ++j)
    for (int k = j; k <= m; ++k) {
      if (!dp[m][j][k]) continue;
      r += dp[m][j][k] * (w[x] + j) % mod;
      r %= mod;
    }
  printf("%lld\n", r);
  return;
}
void solve2(int x) {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  long long zi, mu;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= i; ++j)
      for (int k = j; k <= i; ++k) {
        if (!dp[i][j][k]) continue;
        mu = inv[sum - k * 2 + i];
        zi = (w[x] - j) % mod;
        (dp[i + 1][j + 1][k + 1] += dp[i][j][k] * zi % mod * mu % mod) %= mod;
        zi = (sb - w[x] - k + j + mod) % mod;
        (dp[i + 1][j][k + 1] += dp[i][j][k] * zi % mod * mu % mod) %= mod;
        zi = (sa + i - k + mod) % mod;
        (dp[i + 1][j][k] += dp[i][j][k] * zi % mod * mu % mod) %= mod;
      }
  long long r = 0;
  for (int j = 0; j <= m; ++j)
    for (int k = j; k <= m; ++k) {
      if (!dp[m][j][k]) continue;
      r += dp[m][j][k] * max(0, w[x] - j) % mod;
      r %= mod;
    }
  printf("%lld\n", r);
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &w[i]);
    sa += a[i] * w[i];
    sb += (a[i] ^ 1) * w[i];
  }
  sum = sa + sb;
  inv[1] = 1;
  for (int i = 2; i <= sum * 2; ++i)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 1; i <= n; ++i)
    if (a[i])
      solve1(i);
    else
      solve2(i);
  return 0;
}
