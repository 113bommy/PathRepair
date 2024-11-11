#include <bits/stdc++.h>
using int64 = long long;
using uchar = unsigned char;
constexpr int mxdg(262144);
constexpr int p(998244353);
constexpr int hfp(p >> 1);
constexpr int proot(3);
namespace IOManager {
constexpr int FILESZ(131072);
char buf[FILESZ];
const char *ibuf = buf, *tbuf = buf;
struct IOManager {
  inline char gc() {
    return (ibuf == tbuf) &&
                   (tbuf = (ibuf = buf) + fread(buf, 1, FILESZ, stdin),
                    ibuf == tbuf)
               ? EOF
               : *ibuf++;
  }
  template <class _Tp>
  inline operator _Tp() {
    _Tp s = 0u;
    char c = gc();
    for (; c < 48; c = gc())
      ;
    for (; c > 47; c = gc()) s = (_Tp)(s * 10u + c - 48u);
    return s;
  }
};
}  // namespace IOManager
IOManager::IOManager io;
namespace math_template {
using Z = int;
using mZ = long long;
template <class _Tp>
inline void swap(_Tp& x, _Tp& y) {
  _Tp z = x;
  x = y;
  y = z;
}
template <class _Tp>
inline Z fpow(_Tp v, int n) {
  Z pw = 1;
  for (; n; n >>= 1, v = (mZ)v * v % p)
    if (n & 1) pw = (mZ)pw * v % p;
  return pw;
}
template <class x_tp, class y_tp>
inline void inc(x_tp& x, const y_tp& y) {
  (p - y <= x) ? (x += y - p) : (x += y);
}
template <class x_tp, class y_tp>
inline void dec(x_tp& x, const y_tp& y) {
  x -= y;
  (x < 0) && (x += p);
}
template <class x_tp, class y_tp>
inline Z pls(const x_tp& x, const y_tp& y) {
  return (x < p - y) ? (x + y) : (x - p + y);
}
template <class x_tp, class y_tp>
inline Z sub(const x_tp& x, const y_tp& y) {
  return (x < y) ? (x - y + p) : (x - y);
}
template <class _Tp>
inline _Tp gcd(const _Tp& x, const _Tp& y) {
  return y ? gcd(y, x % y) : x;
}
template <class _Tp>
inline _Tp lcm(const _Tp& x, const _Tp& y) {
  return x / gcd(x, y) * y;
}
template <class _Tp, class x_tp>
inline void exgcd(const _Tp& x, const _Tp& y, x_tp& a, x_tp& b) {
  if (y)
    exgcd(y, x % y, b, a), b -= x / y * a;
  else
    a = 1, b = 0;
}
inline Z inv(const Z& v, const Z& mp) {
  Z x, y;
  exgcd(v, mp, x, y);
  return x < 0 ? x + mp : x;
}
template <class _Tp>
inline Z div2(const _Tp& v) {
  return (v & 1) ? (v + p) >> 1 : (v >> 1);
}
template <class x_tp, class y_tp>
inline x_tp Min(const x_tp& x, const y_tp& y) {
  return x < y ? x : y;
}
template <class x_tp, class y_tp>
inline x_tp Max(const x_tp& x, const y_tp& y) {
  return x > y ? x : y;
}
template <class x_tp, class y_tp>
inline void chkMin(x_tp& x, const y_tp& y) {
  (x > y) && (x = y);
}
template <class x_tp, class y_tp>
inline void chkMax(x_tp& x, const y_tp& y) {
  (x < y) && (x = y);
}
template <class x_tp, class y_tp>
inline bool bchkMin(x_tp& x, const y_tp& y) {
  return (x > y) && (x = y, 1);
}
template <class x_tp, class y_tp>
inline bool bchkMax(x_tp& x, const y_tp& y) {
  return (x < y) && (x = y, 1);
}
}  // namespace math_template
namespace poly {
using namespace math_template;
using poly_t = Z[mxdg];
using poly = Z* const;
inline int calcpw2(const int& n) {
  int pw2 = 1;
  for (; pw2 < n; pw2 += pw2)
    ;
  return pw2;
}
poly_t wn, iwn;
inline void polyinit() {
  const Z wnv = fpow(proot, (p - 1) / mxdg);
  const Z iwnv = fpow(wnv, p - 2);
  wn[0] = iwn[0] = 1;
  Z w = 1, iw = 1;
  for (int i = 1; i != mxdg; ++i) {
    w = (mZ)w * wnv % p;
    wn[i] = w;
    iw = (mZ)iw * iwnv % p;
    iwn[i] = iw;
  }
}
void DFT(poly& A, const int& n) {
  for (int i = 0, j = 0; i != n; ++i) {
    if (i < j) swap(A[i], A[j]);
    for (int k = n >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
  Z* const td = A + n;
  for (int l = 1, tp = mxdg >> 1; l != n; l += l, tp >>= 1)
    for (Z *i = A, *w, z; i != td; i += l + l)
      for (int j = (w = wn, 0); j != l; ++j, w += tp)
        z = (mZ)i[j + l] * *w % p, i[j + l] = sub(i[j], z), inc(i[j], z);
}
void IDFT(poly& A, const int& n) {
  for (int i = 0, j = 0; i != n; ++i) {
    if (i < j) swap(A[i], A[j]);
    for (int k = n >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
  Z* const td = A + n;
  for (int l = 1, tp = mxdg >> 1; l != n; l += l, tp >>= 1)
    for (Z *i = A, *w, z; i != td; i += l + l)
      for (int j = (w = iwn, 0); j != l; ++j, w += tp)
        z = (mZ)i[j + l] * *w % p, i[j + l] = sub(i[j], z), inc(i[j], z);
  const Z invn = fpow(n, p - 2);
  for (Z* i = A; i != td; ++i) *i = (mZ)*i * invn % p;
}
inline void cp(const Z* const& sl, const Z* const& sr, Z* const& dl,
               Z* const& dr) {
  std::copy(sl, sr, dl);
  if (sr - sl < dr - dl) std::fill(dl + (sr - sl), dr, 0);
}
void polyinv(const poly& h, poly& f, const int& n) {
  static poly_t inv_t;
  std::fill(f, f + n + n, 0);
  f[0] = fpow(h[0], p - 2);
  for (int t = 1; (1 << t) <= n; ++t) {
    const int deg1 = 1 << t, deg2 = deg1 << 1;
    cp(h, h + deg1, inv_t, inv_t + deg2);
    DFT(f, deg2);
    DFT(inv_t, deg2);
    for (int i = 0; i != deg2; ++i)
      f[i] = (mZ)f[i] * sub(2ll, (mZ)inv_t[i] * f[i] % p) % p;
    IDFT(f, deg2);
    std::fill(f + deg1, f + deg2, 0);
  }
}
void polysqrt(const poly& h, poly& f, const int& n) {
  static poly_t sqrt_t, inv_t;
  std::fill(f, f + n + n, 0);
  f[0] = 1;
  for (int t = 1; (1 << t) <= n; ++t) {
    const int deg1 = 1 << t, deg2 = deg1 << 1;
    polyinv(f, inv_t, deg1);
    cp(h, h + deg1, sqrt_t, sqrt_t + deg2);
    DFT(sqrt_t, deg2);
    DFT(inv_t, deg2);
    for (int i = 0; i != deg2; ++i) sqrt_t[i] = (mZ)inv_t[i] * sqrt_t[i] % p;
    IDFT(sqrt_t, deg2);
    for (int i = deg1 >> 1; i != deg1; ++i) f[i] = div2(sqrt_t[i]);
    std::fill(f + deg1, f + deg2, 0);
  }
}
}  // namespace poly
using namespace poly;
poly_t C, rt;
int main() {
  polyinit();
  int n = io;
  const int m((int)io + 1), deg = calcpw2(m);
  C[0] = 1;
  for (int i; n; --n)
    if ((i = io) < m) C[i] = 998244349;
  polysqrt(C, rt, deg);
  inc(rt[0], 1);
  polyinv(rt, C, deg);
  int* const td = C + m;
  for (int* i = C + 1; i != td; ++i)
    printf("%d\n", *i <= hfp ? *i + *i : (*i + *i - p));
  return 0;
}
