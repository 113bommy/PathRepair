#include <bits/stdc++.h>
const long long MAXN = 200000 + 5, MOD = 998244353;
long long n, k, inv[MAXN], fac[MAXN], ans;
long long fpow(long long a, long long b) {
  long long sum = 1;
  for (; b; b >>= 1, a = a * a % MOD)
    if (b & 1) sum = sum * a % MOD;
  return sum;
}
signed main() {
  std::cin >> n >> k;
  fac[0] = 1;
  if (k >= n) return std::cout << 0, 0;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
  inv[n] = fpow(fac[n], MOD - 2);
  for (long long i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
  for (long long i = 0; i <= n; i++) {
    long long res = fac[n - k] * inv[i] % MOD * inv[n - k - i] % MOD *
                    fpow(n - k - i, n) % MOD;
    if (i & 1)
      ans = (res < ans) ? ans - res : ans - res + MOD;
    else
      ans = (ans + res) % MOD;
  }
  ans = ans * (k ? 2 : 1) * fac[n] % MOD * inv[k] % MOD * inv[n - k] % MOD;
  std::cout << ans;
  return 0;
}
