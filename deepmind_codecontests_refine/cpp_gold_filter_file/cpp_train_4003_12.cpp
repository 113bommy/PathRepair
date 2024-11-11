#include <bits/stdc++.h>
const int N = 4e5 + 10;
const int mod = 998244353;
int n, m, i, j, k;
int a[N], b[N], c[N], d[N];
inline int qpow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) c = 1ll * c * a % mod;
  return c;
}
namespace con_poly {
int lim, L;
int rev[N], inva[N], dera[N], derb[N];
inline void ntt_init(int items) {
  lim = 1, L = 0;
  while (lim < items) lim <<= 1, L++;
  for (int i = 0; i < lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << L - 1);
}
inline void ntt(int a[], int type) {
  for (int i = 0; i < lim; i++)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int gn = qpow(type == 1 ? 3 : 332748118, (mod - 1) / (mid << 1));
    for (int i = 0, r = mid << 1; i < lim; i += r) {
      for (int j = 0, g = 1; j < mid; j++, g = 1ll * g * gn % mod) {
        int x = a[i + j], y = 1ll * g * a[i + j + mid] % mod;
        a[i + j] = (x + y) % mod;
        a[i + j + mid] = (x - y + mod) % mod;
      }
    }
  }
  if (type == -1) {
    int inv = qpow(lim, mod - 2);
    for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * inv % mod;
  }
}
inline void poly_mul(int c[], int a[], int b[], int la, int lb) {
  ntt_init(la + lb);
  ntt(a, 1), ntt(b, 1);
  for (int i = 0; i < lim; i++) c[i] = 1ll * a[i] * b[i] % mod;
  ntt(c, -1);
}
void poly_inv(int deg, int a[], int b[]) {
  static int c[N];
  if (deg == 1) return void(b[0] = qpow(a[0], mod - 2));
  poly_inv((deg + 1) >> 1, a, b);
  ntt_init(deg << 1);
  for (int i = 0; i < deg; i++) c[i] = a[i];
  for (int i = deg; i < lim; i++) c[i] = 0;
  ntt(b, 1), ntt(c, 1);
  for (int i = 0; i < lim; i++)
    b[i] = 1ll * (2ll - 1ll * b[i] * c[i] % mod + mod) % mod * b[i] % mod;
  ntt(b, -1);
  for (int i = deg; i < lim; i++) b[i] = 0;
}
void poly_sqrt(int deg, int a[], int b[]) {
  static int c[N], d[N];
  if (deg == 1) return void(b[0] = 1);
  poly_sqrt((deg + 1) >> 1, a, b);
  for (int i = 0, ei = deg << 1; i < ei; i++) c[i] = 0;
  poly_inv(deg, b, c);
  ntt_init(deg << 1);
  for (int i = 0; i < deg; i++) d[i] = a[i];
  for (int i = deg; i < lim; i++) d[i] = 0;
  ntt(b, 1), ntt(c, 1), ntt(d, 1);
  for (int i = 0; i < lim; i++)
    b[i] = 1ll * (b[i] + 1ll * c[i] * d[i] % mod) % mod * 499122177ll % mod;
  ntt(b, -1);
  for (int i = deg; i < lim; i++) b[i] = 0;
}
}  // namespace con_poly
using namespace con_poly;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    a[x] = 1;
  }
  for (int i = 1; i <= m; i++) a[i] = (a[i] * -4 + mod) % mod;
  a[0] = 1;
  poly_sqrt(m + 1, a, b);
  b[0]++;
  poly_inv(m + 1, b, c);
  for (int i = 1; i <= m; i++) printf("%lld\n", c[i] * 2ll % mod);
  return 0;
}
