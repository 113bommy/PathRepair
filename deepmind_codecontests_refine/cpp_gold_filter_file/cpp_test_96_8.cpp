#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
inline long long qpow(long long b, long long e, long long m) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - y * (a / b);
  return d;
}
long long dp[509][509], C[509][509];
int n, x;
void init() {
  for (int i = 0; i <= 500; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
}
int main() {
  scanf("%d%d", &n, &x);
  init();
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (j < i) {
        dp[i][j] = qpow(j, i, mod) - qpow(j - 1, i, mod);
        dp[i][j] = (dp[i][j] % mod + mod) % mod;
      } else {
        for (int k = 2; k <= i; k++) {
          dp[i][j] +=
              dp[k][j - i + 1] * C[i][k] % mod * qpow(i - 1, i - k, mod) % mod;
          dp[i][j] %= mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= x; i++) ans += dp[n][i], ans %= mod;
  printf("%lld\n", ans);
}
