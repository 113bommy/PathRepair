#include <bits/stdc++.h>
using namespace std;
namespace io {
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class I>
inline void fr(I &num) {
  num = 0;
  register char c = nc();
  register int p = 1;
  while (c < '0' || c > '9') c == '-' ? p = -1, c = nc() : c = nc();
  while (c >= '0' && c <= '9') num = num * 10 + c - '0', c = nc();
  num *= p;
}
template <class I>
inline I Max(I p, I q) {
  return p > q ? p : q;
}
template <class I>
inline I Min(I p, I q) {
  return p < q ? p : q;
}
template <class I>
inline I A(I x) {
  return x < 0 ? -x : x;
}
template <class I>
inline void sp(I &p, I &q) {
  I x = p;
  p = q, q = x;
}
template <class I>
inline void ckMax(I &p, I q) {
  p = (p > q ? p : q);
}
template <class I>
inline void ckMin(I &p, I q) {
  p = (p < q ? p : q);
}
};  // namespace io
using io ::A;
using io ::ckMax;
using io ::ckMin;
using io ::fr;
using io ::Max;
using io ::Min;
using io ::nc;
using io ::sp;
const int N = 1000005, S = 2000;
int n, pw[N], a[N], vs[N], cn[N], m;
bitset<2005> f[1 << 16 | 5];
int main() {
  scanf("%d%d", &n, &m);
  register int i, j, s, lim = 1 << n;
  for (i = pw[0] = 1; i <= 30; ++i) pw[i] = pw[i - 1] << 1;
  for (i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (s = 0, f[0][0] = 1; s < lim; ++s) {
    for (j = S / m; j; --j) f[s][j] = f[s][j] | f[s][j * m];
    for (j = 0; j < n; ++j)
      if (!(s >> j & 1)) f[s | pw[j]] = f[s] << a[j];
  }
  if (!f[--lim][s = 1]) return puts("NO"), 0;
  puts("YES");
  while (lim)
    for (s *= m, i = 0; i < n; ++i)
      if (lim >> i & 1) {
        ++cn[i];
        if (s >= a[i] && f[lim ^ pw[i]][s - a[i]]) lim ^= pw[i], s -= a[i];
      }
  for (register int p1, p2 = i = 1; i < n; ++i) {
    for (p1 = p2 = j = 0; j < n; ++j) {
      if (vs[j]) continue;
      if (cn[j] >= cn[p2]) p2 = j;
      if (cn[p2] >= cn[p1]) sp(p1, p2);
    }
    printf("%d %d\n", a[p1], a[p2]), a[p1] += a[p2];
    while (!(a[p1] % m)) a[p1] /= m, --cn[p1];
    vs[p2] = 1, cn[p2] = -1;
  }
  return 0;
}
