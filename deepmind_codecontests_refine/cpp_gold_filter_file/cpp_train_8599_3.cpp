#include <bits/stdc++.h>
using std::max;
using std::swap;
const int mod = 998244353, wg = 3, ig = 332748118;
int r[65536], a[65536], b[65536], squre[50002], f0[50000], f1[50000], f2[50000];
int g[50002] = {1, 0, 1, 0}, g0[50000], g1[50000], g2[50000];
int *w, len, inv, wn[65536] = {1}, iwn[65536] = {1};
int pow(int x, int p) {
  int res(1);
  while (p) {
    if (p & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    p >>= 1;
  }
  return res;
}
void ntt(int* t, int* ow = wn) {
  for (int i(0); i < len; ++i) {
    if (i < r[i]) swap(t[i], t[r[i]]);
  }
  for (int i(1), j(2), step(len >> 1); i < len; i <<= 1, j <<= 1, step >>= 1) {
    for (int k(0); k < len; k += j) {
      w = ow;
      for (int l(k); l < k + i; ++l, w += step) {
        int tmp(1ll * (*w) * t[l + i] % mod);
        t[l + i] = t[l] - tmp;
        if (t[l + i] < 0) t[l + i] += mod;
        t[l] += tmp;
        if (t[l] >= mod) t[l] -= mod;
      }
    }
  }
  if (ow == iwn) {
    for (int i(0); i < len; ++i) t[i] = 1ll * t[i] * inv % mod;
  }
}
void get_f(int lo, int hi) {
  if (hi == lo + 1) {
    f0[lo] = (f0[lo] + g0[lo]) % mod;
    f1[lo] = (f1[lo] + g1[lo]) % mod;
    f2[lo] = (f2[lo] + g2[lo]) % mod;
  } else {
    int mi((lo + hi) >> 1);
    get_f(lo, mi);
    int tmp(hi - lo), ti(max(lo + 3, mi));
    len = 1;
    while (len <= tmp) len <<= 1;
    inv = mod - (mod - 1) / len;
    for (int i(0); i < len; ++i) r[i] = (r[i >> 1] | ((i & 1) ? len : 0)) >> 1;
    for (int i(1), j(pow(wg, (mod - 1) / len)); i < len; ++i)
      wn[i] = 1ll * wn[i - 1] * j % mod;
    for (int i(1), j(pow(ig, (mod - 1) / len)); i < len; ++i)
      iwn[i] = 1ll * iwn[i - 1] * j % mod;
    for (int i(0); i <= tmp - 2; ++i) a[i] = g0[i];
    for (int i(lo); i < mi; ++i) b[i - lo] = f0[i];
    ntt(a);
    ntt(b);
    for (int i(0); i < len; ++i) a[i] = 1ll * a[i] * b[i] % mod;
    ntt(a, iwn);
    for (int i(mi); i < hi; ++i) f0[i] = (f0[i] + a[i - 1 - lo]) % mod;
    for (int i(0); i <= tmp - 2; ++i) a[i] = g1[i];
    for (int i(tmp - 1); i < len; ++i) a[i] = 0;
    ntt(a);
    for (int i(0); i < len; ++i) b[i] = 1ll * a[i] * b[i] % mod;
    ntt(b, iwn);
    for (int i(mi); i < hi; ++i) f1[i] = (f1[i] + b[i - 1 - lo]) % mod;
    for (int i(lo); i < mi; ++i) b[i - lo] = f1[i];
    for (int i(mi - lo); i < len; ++i) b[i] = 0;
    ntt(b);
    for (int i(0); i < len; ++i) a[i] = 1ll * a[i] * b[i] % mod;
    ntt(a, iwn);
    for (int i(mi); i < hi; ++i) f2[i] = (f2[i] + a[i - 1 - lo]) % mod;
    for (int i(ti); i < hi; ++i) f0[i] = (f0[i] + a[i - 3 - lo]) % mod;
    for (int i(0); i <= tmp - 2; ++i) a[i] = g2[i];
    for (int i(tmp - 1); i < len; ++i) a[i] = 0;
    ntt(a);
    for (int i(0); i < len; ++i) b[i] = 1ll * a[i] * b[i] % mod;
    ntt(b, iwn);
    for (int i(ti); i < hi; ++i) f1[i] = (f1[i] + b[i - 3 - lo]) % mod;
    for (int i(lo); i < mi; ++i) b[i - lo] = f2[i];
    for (int i(mi - lo); i < len; ++i) b[i] = 0;
    ntt(b);
    for (int i(0); i < len; ++i) a[i] = 1ll * a[i] * b[i] % mod;
    ntt(a, iwn);
    for (int i(ti); i < hi; ++i) f2[i] = (f2[i] + a[i - 3 - lo]) % mod;
    for (int i(0); i < len; ++i) a[i] = b[i] = 0;
    get_f(mi, hi);
  }
}
int main() {
  int n, ans;
  scanf("%d", &n);
  for (int i(4); i <= n + 1; ++i) g[i] = (g[i - 2] + g[i - 4]) % mod;
  for (int i(0); i <= n + 1; ++i) squre[i] = 1ll * i * i % mod;
  for (int i(0); i < n; ++i) {
    g0[i] = 1ll * g[i] * squre[i] % mod;
    g1[i] = 1ll * g[i] * squre[i + 1] % mod;
    g2[i] = 1ll * g[i] * squre[i + 2] % mod;
  }
  get_f(0, n);
  ans = 1ll * g[n + 1] * squre[n - 1] % mod * n % mod;
  for (int i(2); i <= n - 2; ++i)
    ans = (1ll * i * squre[i - 1] % mod *
               ((1ll * g[i - 1] * f0[n - 1 - i] +
                 1ll * 2 * g[i - 2] * f1[n - i - 2]) %
                mod) +
           ans) %
          mod;
  for (int i(3); i <= n - 3; ++i)
    ans =
        (1ll * i * squre[i - 1] % mod * g[i - 3] % mod * f2[n - i - 3] + ans) %
        mod;
  printf("%d", ans);
  return 0;
}
