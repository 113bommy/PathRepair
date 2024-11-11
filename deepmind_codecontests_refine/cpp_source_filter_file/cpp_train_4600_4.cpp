#include <bits/stdc++.h>
const int N = 3e6 + 10;
long long fac[N], inv[N];
const int mod = 998244353;
int n, m;
inline long long Power(long long a, long long x) {
  long long ans = 1;
  while (x) {
    if (x & 1) ans = ans * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return ans;
}
inline long long Solve(int k) {
  return fac[n + m] * inv[m + k] % mod * inv[n - k] % mod;
}
int main() {
  scanf("%d%d", &n, &m);
  fac[0] = 1;
  for (int i = 1; i <= n + m; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  inv[n + m] = Power(fac[n + m], mod - 2);
  for (int i = n + m - 1; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % mod;
  }
  long long ans = 0;
  for (int k = std::max(0, n - m); k <= n; k++) {
    ans = (ans + (Solve(k) - Solve(k + 1) + mod) % mod * k % mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
