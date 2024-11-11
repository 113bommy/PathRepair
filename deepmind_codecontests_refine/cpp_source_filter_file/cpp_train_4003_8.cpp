#include <bits/stdc++.h>
int a[400005] = {0}, b[400005] = {0}, cl[400005], d[400005] = {0},
    d2[400005] = {0}, res[400005] = {0}, s[400005] = {0}, rev[400005], n, m;
int qpow(int a, int b) {
  if (b == 0) return 1;
  int d = qpow(a, b >> 1);
  d = (long long)d * d % 998244353;
  if (b & 1) d = (long long)d * a % 998244353;
  return d;
}
void NTT(int *a, int type, int lim) {
  for (int i = 0; i < lim; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
  for (int i = 0; i < lim; ++i)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int len = 1; len < lim; len <<= 1) {
    int wn = qpow(3, (998244353 - 1) / (len << 1)), r = len << 1;
    if (type == -1) wn = qpow(wn, 998244353 - 2);
    for (int j = 0; j < lim; j += r)
      for (int w = 1, k = 0; k < len; ++k, w = (long long)w * wn % 998244353) {
        int x = a[j + k];
        int y = (long long)w * a[j + k + len] % 998244353;
        a[j + k] = (x + y) % 998244353;
        a[j + k + len] = (x - y + 998244353) % 998244353;
      }
  }
  if (type == -1)
    for (int i = 0; i < lim; ++i)
      a[i] = (long long)a[i] * qpow(lim, 998244353 - 2) % 998244353;
}
void polyInv(int len, int *a, int *c) {
  if (len == 1) {
    c[0] = qpow(a[0], 998244353 - 2);
    return;
  }
  polyInv((len + 1) >> 1, a, c);
  int lim = 1;
  while (lim < (len << 1)) lim <<= 1;
  for (int i = 0; i < lim; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
  for (int i = len; i < lim; ++i) c[i] = 0;
  for (int i = 0; i < len; ++i) cl[i] = a[i];
  for (int i = len; i < lim; ++i) cl[i] = 0;
  NTT(cl, 1, lim);
  NTT(c, 1, lim);
  for (int i = 0; i < lim; ++i)
    c[i] = (long long)(2ll - (long long)cl[i] * c[i] % 998244353 + 998244353) %
           998244353 * (long long)c[i] % 998244353;
  NTT(c, -1, lim);
  for (int i = len; i < lim; ++i) c[i] = 0;
}
void polySqrt(int len, int *a, int *c) {
  if (len == 1) {
    c[0] = a[0];
    return;
  }
  polySqrt((len + 1) >> 1, a, c);
  polyInv(len, c, d);
  int lim = 1;
  while (lim <= (len << 1)) lim <<= 1;
  for (int i = len; i < lim; ++i) cl[i] = c[i] = d[i] = 0;
  for (int i = 0; i < len; ++i) cl[i] = a[i];
  for (int i = 0; i < lim; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
  NTT(d, 1, lim);
  NTT(cl, 1, lim);
  for (int i = 0; i < lim; ++i) cl[i] = (long long)cl[i] * d[i] % 998244353;
  NTT(cl, -1, lim);
  for (int i = 0; i < len; ++i)
    cl[i] = (long long)(cl[i] + c[i]) % 998244353 * qpow(2, 998244353 - 2) %
            998244353;
  for (int i = 0; i < len; ++i) c[i] = cl[i];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int t;
    scanf("%d", &t);
    s[t]++;
  }
  for (int i = 1; i <= m; ++i) s[i] = (998244353 - 4 * s[i]) % 998244353;
  s[0]++;
  int lim = 1;
  while (lim <= m) lim <<= 1;
  polySqrt(lim, s, d2);
  d2[0] = (d2[0] + 1) % 998244353;
  polyInv(lim, d2, res);
  for (int i = 0; i <= m; ++i) res[i] = res[i] * 2 % 998244353;
  for (int i = 1; i <= m; ++i) printf("%d\n", res[i]);
}
