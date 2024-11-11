#include <bits/stdc++.h>
int const mod = 998244353;
int n, k, h[200010], fac[200010], inv[200010], a, b, sum;
int pow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return ans;
}
int C(int const &x, int const &y) {
  return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", h + i);
  if (n == 1) return puts("0"), 0;
  for (int i = 1; i <= n; i++) {
    int s;
    if (i == n)
      s = 1;
    else
      s = i + 1;
    if (h[i] == h[s])
      ++a;
    else
      ++b;
  }
  fac[0] = 1;
  for (int i = 1; i <= b; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[b] = pow(fac[b], mod - 2);
  for (int i = b - 1; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= b; i++) {
    int s;
    if (i & 1)
      s = pow(2, i - 1);
    else
      s = (pow(2, i - 1) - 1ll * C(i, i / 2) * inv[2] % mod + mod) % mod;
    sum = (sum + 1ll * pow(k - 2, b - i) * C(b, b - i) % mod * s % mod) % mod;
  }
  printf("%lld", 1ll * pow(k, a) * sum % mod);
  return 0;
}
