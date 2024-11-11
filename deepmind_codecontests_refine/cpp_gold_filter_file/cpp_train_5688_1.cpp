#include <bits/stdc++.h>
const int N = 5e3 + 7;
const int Mod = 1e9 + 7;
int n, k;
long long dp[N];
long long qpow(long long x, int y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  dp[0] = 1;
  long long mul = 1;
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    mul = (mul * x) % Mod;
    for (int j = i; j; j--) dp[j] = (dp[j] * x % Mod - dp[j - 1] + Mod) % Mod;
    dp[0] = dp[0] * x % Mod;
  }
  int rg = n < k ? n : k;
  long long ans = dp[0], ret = 1, inv = qpow(n, Mod - 2);
  for (int i = 1; i <= rg; i++)
    ans = (ans +
           (ret = (ret * inv % Mod * (k - i + 1)) % Mod) % Mod * dp[i] % Mod) %
          Mod;
  printf("%lld", (mul - ans % Mod + Mod) % Mod);
}
