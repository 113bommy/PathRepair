#include <bits/stdc++.h>
using std::swap;
const double pi = acos(-1);
int s[2][30001], r[65536], n, mod, ans, len(1);
double inv;
struct cp {
  double re, im;
  cp() {}
  cp(const double& r, const double& i) : re(r), im(i) {}
  inline cp operator+(const cp& p) { return cp(re + p.re, im + p.im); }
  inline cp operator-(const cp& p) { return cp(re - p.re, im - p.im); }
  inline cp operator*(const cp& p) {
    return cp(re * p.re - im * p.im, re * p.im + im * p.re);
  }
  inline void operator*=(const double& p) { re *= p, im *= p; }
} a[65536], b[2][65536], *w, wn[65536], iwn[65536], cp0(0, 0);
void fft(cp* t, cp* ow = wn) {
  for (int i(0); i < len; ++i) {
    if (i < r[i]) swap(t[i], t[r[i]]);
  }
  for (int i(1), j(2), step(len >> 1); i < len; i <<= 1, j <<= 1, step >>= 1) {
    for (int k(0); k < len; k += j) {
      w = ow;
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
void get_ans(int m, bool gt) {
  if (m == 1) {
    ans = s[1][0] = s[1][1] = 1;
    return;
  }
  if (m & 1) {
    get_ans(m - 1, 0);
    for (int i(n); i > 0; --i)
      s[1][i] = (s[1][i] + s[0][i - 1] + s[1][i - 1]) % mod;
  } else {
    cp* tb;
    int tmp(m >> 1);
    get_ans(tmp, 1);
    for (int i(0); i < n; ++i) a[i].re = (s[0][i] + s[1][i]) % mod;
    fft(a);
    tmp = tmp & 1;
    for (int i(1); i <= n; ++i) b[0][i].re = s[0][i], b[1][i].re = s[1][i];
    for (int i(0); i < 2; ++i) {
      tb = b[tmp];
      fft(tb);
      for (int j(0); j <= len; ++j) tb[j] = a[j] * tb[j];
      fft(tb, iwn);
      for (int j(0); j <= n; ++j)
        s[i][j] = ((long long)(tb[j].re + 0.5) + s[i][j]) % mod;
      tmp ^= 1;
    }
    for (int i(0); i < len; ++i) a[i] = b[0][i] = b[1][i] = cp0;
  }
  if (gt) {
    for (int i(1); i <= n; i += 2) ans = (ans + s[1][i]) % mod;
  }
}
int main() {
  double tsin, tcos, tp;
  int maxa;
  scanf("%d%d%d", &n, &maxa, &mod);
  if (maxa == 1) {
    printf("0");
    return 0;
  }
  while (len <= n) len <<= 1;
  len <<= 1, inv = 1. / len;
  for (int i(0); i < len; ++i) r[i] = (r[i >> 1] | ((i & 1) ? len : 0)) >> 1;
  for (int i(0); i < len; ++i) {
    tp = 2 * i * pi * inv, tsin = sin(tp), tcos = cos(tp);
    wn[i] = cp(tcos, tsin), iwn[i] = cp(tcos, -tsin);
  }
  get_ans(maxa >> 1, 1);
  printf("%d", ans);
  return 0;
}
