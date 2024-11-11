#include <bits/stdc++.h>
using std::swap;
const double pi = acos(-1);
const int mod = 1000000007, md = 32767;
double inv;
int k, len(1), r[65536], fac[30001] = {1}, ifac[30001] = {1}, tx[65536],
                         ans[65536];
struct cp {
  double re, im;
  cp() {}
  cp(const double& r, const double& i) : re(r), im(i) {}
  inline cp operator+(const cp& p) { return cp(re + p.re, im + p.im); }
  inline cp operator-(const cp& p) { return cp(re - p.re, im - p.im); }
  inline cp operator*(const cp& p) {
    return cp(re * p.re - im * p.im, re * p.im + im * p.re);
  }
  inline cp operator~() { return cp(re, -im); }
  inline void operator*=(const double& p) { re *= p, im *= p; }
} wn[65536], iwn[65536], f[65536], tf[65536], g[65536], a0[65536], b0[65536],
    cp0(0, 0), pr0(0.5, 0), pr1(0, -0.5), I(0, 1);
int qpow(int x, int p) {
  int res(1);
  while (p) {
    if (p & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    p >>= 1;
  }
  return res;
}
void fft(cp* t, cp* ow = wn) {
  for (int i(0); i < len; ++i) {
    if (i < r[i]) swap(t[i], t[r[i]]);
  }
  for (int i(1), j(2), step(len >> 1); i < len; i <<= 1, j <<= 1, step >>= 1) {
    for (int k(0); k < len; k += j) {
      cp* w(ow);
      for (int l(k); l < k + i; ++l, w += step) {
        cp tmp((*w) * t[l + i]);
        t[l + i] = t[l] - tmp;
        t[l] = t[l] + tmp;
      }
    }
  }
  if (ow == iwn) {
    for (int i(0); i < len; ++i) t[i] *= inv;
  }
}
void get_ans(int p) {
  int s(2), tp;
  long long a0a1, ab, b0b1;
  cp tmp;
  ans[0] = 1;
  while (p) {
    for (int i(0); i <= k; ++i) f[i] = cp(tx[i] >> 15, tx[i] & md);
    fft(f);
    for (int i(0); i < len; ++i) {
      tmp = ~f[(len - i) & (len - 1)];
      a0[i] = (f[i] + tmp) * pr0, b0[i] = (f[i] - tmp) * pr1;
    }
    if (p & 1) {
      for (int i(0), j(1); i <= k; ++i, j = 1ll * j * s % mod) {
        tp = 1ll * ans[i] * j % mod;
        g[i] = cp(tp >> 15, tp & md);
      }
      fft(g);
      for (int i(0); i < len; ++i) tf[i] = a0[i] * g[i], g[i] = b0[i] * g[i];
      fft(tf, iwn);
      fft(g, iwn);
      for (int i(0); i <= k; ++i) {
        a0a1 = ((long long)(tf[i].re + 0.5) % mod) << 30;
        ab = (((long long)(tf[i].im + 0.5) + (long long)(g[i].re + 0.5)) % mod)
             << 15;
        b0b1 = (long long)(g[i].im + 0.5) % mod;
        ans[i] = (a0a1 + ab + b0b1) % mod;
      }
      for (int i(k + 1); i < len; ++i) tf[i] = g[i] = cp0;
    }
    for (int i(0), j(1); i <= k; ++i, j = 1ll * j * s % mod) {
      tp = 1ll * tx[i] * j % mod;
      tf[i] = cp(tp >> 15, tp & md);
    }
    fft(tf);
    for (int i(0); i < len; ++i) f[i] = a0[i] * tf[i], tf[i] = b0[i] * tf[i];
    fft(f, iwn);
    fft(tf, iwn);
    for (int i(0); i <= k; ++i) {
      a0a1 = ((long long)(f[i].re + 0.5) % mod) << 30;
      ab = (((long long)(f[i].im + 0.5) + (long long)(tf[i].re + 0.5)) % mod)
           << 15;
      b0b1 = (long long)(tf[i].im + 0.5) % mod;
      tx[i] = (a0a1 + ab + b0b1) % mod;
    }
    for (int i(k + 1); i < len; ++i) tf[i] = f[i] = cp0;
    p >>= 1, s = 1ll * s * s % mod;
  }
}
int main() {
  int tans(0);
  long long n;
  scanf("%lld%d", &n, &k);
  if (n > k) {
    printf("0");
    return 0;
  }
  for (int i(1); i <= k; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[k] = qpow(fac[k], mod - 2);
  for (int i(k); i > 1; --i) ifac[i - 1] = 1ll * ifac[i] * i % mod;
  for (int i(1); i <= k; ++i) tx[i] = ifac[i];
  while (len <= k) len <<= 1;
  len <<= 1, inv = 1. / len;
  for (int i(0); i < len; ++i) r[i] = (r[i >> 1] | ((i & 1) ? len : 0)) >> 1;
  for (int i(0); i < len; ++i)
    wn[i] = cp(cos(2 * i * pi * inv), sin(2 * i * pi * inv)), iwn[i] = ~wn[i];
  get_ans(n);
  for (int i(0); i <= k; ++i)
    tans = (tans + 1ll * ans[i] * ifac[k - i] % mod) % mod;
  printf("%lld", 1ll * fac[k] * tans % mod);
  return 0;
}
