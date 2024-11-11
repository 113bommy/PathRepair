#include <bits/stdc++.h>
int const mod = 998244353, g = 3, gi = (mod + 1) / g;
int p[400010], tmp[400010], r[400010], fac[400010], inv[400010], lim = 1 << 18,
                                                                 n, m;
long long nm;
int pow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
void ntt(int *a, int const &type) {
  for (int i = 0; i < lim; i++)
    if (i < r[i]) std::swap(a[i], a[r[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int rt = pow(type == 1 ? g : gi, (mod - 1) / (mid << 1));
    for (int r = mid << 1, j = 0; j < lim; j += r)
      for (int p = 1, k = 0; k < mid; k++, p = 1ll * p * rt % mod) {
        int x = a[j + k], y = 1ll * p * a[j + mid + k] % mod;
        a[j + k] = (x + y) % mod, a[j + mid + k] = (x - y + mod) % mod;
      }
  }
  if (type == -1)
    for (int p = pow(lim, mod - 2), i = 0; i < lim; i++)
      a[i] = 1ll * a[i] * p % mod;
}
int main() {
  for (int i = 0; i < lim; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
  scanf("%d%lld", &n, &nm);
  m = nm % (mod - 1);
  for (int i = 0; i <= n; i++) scanf("%d", p + i);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[n] = pow(fac[n], mod - 2);
  for (int i = n; i; i--) inv[i - 1] = 1ll * inv[i] * i % mod;
  for (int i = 0; i <= n; i++)
    p[i] = 1ll * p[i] * fac[i] % mod, tmp[i] = inv[i];
  for (int i = 0; i <= n; i++)
    if (i < n - i) std::swap(p[i], p[n - i]);
  ntt(p, 1), ntt(tmp, 1);
  for (int i = 0; i < lim; i++) p[i] = 1ll * p[i] * tmp[i] % mod;
  ntt(p, -1);
  for (int i = 0; i <= n; i++)
    if (i < n - i) std::swap(p[i], p[n - i]);
  for (int i = n + 1; i < lim; i++) tmp[i] = p[i] = 0;
  for (int i = 0; i <= n; i++) p[i] = 1ll * p[i] * inv[i] % mod;
  for (int i = 0; i <= n; i++)
    p[i] = 1ll * p[i] * pow(pow(i + 1, mod - 2), m) % mod;
  for (int i = 0; i <= n; i++)
    tmp[i] = inv[i], p[i] = 1ll * p[i] * pow(mod - 1, i) % mod * fac[i] % mod;
  for (int i = 0; i <= n; i++)
    if (i < n - i) std::swap(p[i], p[n - i]);
  ntt(p, 1), ntt(tmp, 1);
  for (int i = 0; i < lim; i++) p[i] = 1ll * p[i] * tmp[i] % mod;
  ntt(p, -1);
  for (int i = 0; i <= n; i++)
    if (i < n - i) std::swap(p[i], p[n - i]);
  for (int i = n + 1; i < lim; i++) p[i] = 0;
  for (int i = 0; i <= n; i++)
    p[i] = 1ll * p[i] * pow(mod - 1, i) % mod * inv[i] % mod;
  for (int i = 0; i <= n; i++) printf("%d ", p[i]);
  return 0;
}
