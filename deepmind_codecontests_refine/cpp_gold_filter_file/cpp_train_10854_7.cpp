#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long dp[2000005];
long long fra[4000005];
long long inv[4000005];
int mod = 998244353;
long long f_pow(long long a, long long b) {
  long long res = 1, temp = a;
  while (b) {
    if (b & 1) res = res * temp % mod;
    temp = temp * temp % mod;
    b >>= 1;
  }
  return res;
}
long long C(long long a, long long b) {
  return fra[a] * inv[b] % mod * inv[a - b] % mod;
}
long long invC(long long a, long long b) {
  return inv[a] * fra[b] % mod * fra[a - b] % mod;
}
void solve() {
  fra[0] = 1;
  for (int i = 1; i <= 4000000; i++) fra[i] = fra[i - 1] * i % mod;
  inv[4000000] = f_pow(fra[4000000], mod - 2) % mod;
  for (int i = 3999999; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  dp[0] = 0;
  int n, m;
  scanf("%d %d", &n, &m);
  long long tmp = 0;
  for (int i = 0; i <= n; i++) {
    tmp += (i + 1) * C(n - i + m - 1, m - 1) % mod * invC(n + m, m) % mod;
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = (sum * invC(i + m, m) + tmp) % mod *
            f_pow((1 - C(i + m - 1, m - 1) * invC(i + m, m) % mod + mod) % mod,
                  mod - 2) %
            mod;
    sum += dp[i] * C(i + m - 1, m - 1) % mod;
    sum %= mod;
  }
  printf("%lld\n", dp[n]);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
