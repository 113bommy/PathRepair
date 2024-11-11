#include <bits/stdc++.h>
using int64 = long long;
using uchar = unsigned char;
constexpr int mxdg(262144);
constexpr int p(998244353);
constexpr int hfp(p >> 1);
constexpr int proot(3);
template <class _Tp>
inline void swap(_Tp& x, _Tp& y) {
  _Tp z = x;
  x = y;
  y = z;
}
template <class _Tp>
inline int fpow(_Tp v, int n) {
  int pw = 1;
  for (; n; n >>= 1, v = (int64)v * v % p)
    if (n & 1) pw = (int64)pw * v % p;
  return pw;
}
template <class _Tpx, class _Tpy>
inline void inc(_Tpx& x, const _Tpy& y) {
  (p - y <= x) ? (x += y - p) : (x += y);
}
template <class _Tpx, class _Tpy>
inline void dec(_Tpx& x, const _Tpy& y) {
  x -= y;
  (x < 0) && (x += p);
}
template <class _Tpx, class _Tpy>
inline _Tpx pls(const _Tpx& x, const _Tpy& y) {
  return (x < p - y) ? (x + y) : (x - p + y);
}
template <class _Tpx, class _Tpy>
inline _Tpx sub(const _Tpx& x, const _Tpy& y) {
  return (x < y) ? (x - y + p) : (x - y);
}
template <class _Tp>
inline int div2(const _Tp& v) {
  return (v & 1) ? (v + p) >> 1 : (v >> 1);
}
template <class _Tp>
inline _Tp Max(const _Tp& x, const _Tp& y) {
  return x > y ? x : y;
}
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
int omg_n;
int omg[mxdg + 1], iomg[mxdg + 1];
inline void init_omg(const int& n = mxdg) {
  omg_n = n;
  const int ob = fpow(proot, (p - 1) / n);
  const int iob = fpow(ob, p - 2);
  omg[0] = iomg[0] = 1;
  for (int i = 1, v = 1, iv = 1; i != n; ++i) {
    v = (int64)v * ob % p;
    omg[i] = v;
    iv = (int64)iv * iob % p;
    iomg[i] = iv;
  }
}
template <class _Tp>
void DFT(_Tp* A, const int& deg) {
  for (int i = 0, j = 0; i != deg; ++i) {
    if (i < j) swap(A[i], A[j]);
    for (int k = deg >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
  _Tp* const td = A + deg;
  for (int l = 1, tp = omg_n >> 1; l < deg; l += l, tp >>= 1)
    for (_Tp *i = A, z; i < td; i += l + l)
      for (int j = 0, *w = omg; j != l; ++j, w += tp)
        z = (int64)i[j + l] * *w % p, i[j + l] = sub(i[j], z), inc(i[j], z);
}
template <class _Tp>
void IDFT(_Tp* A, const int& deg) {
  for (int i = 0, j = 0; i != deg; ++i) {
    if (i < j) swap(A[i], A[j]);
    for (int k = deg >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
  _Tp* const td = A + deg;
  for (int l = 1, tp = omg_n >> 1; l < deg; l += l, tp >>= 1)
    for (_Tp *i = A, z; i < td; i += l + l)
      for (int j = 0, *w = iomg; j != l; ++j, w += tp)
        z = (int64)i[j + l] * *w % p, i[j + l] = sub(i[j], z), inc(i[j], z);
  const int invdeg = fpow(deg, p - 2);
  for (int i = 0; i != deg; ++i) A[i] = (int64)A[i] * invdeg % p;
}
int tmp[3][mxdg + 1];
inline void cp(const int* const& srcs, const int* const& srct, int* const& dsts,
               int* const& dstt) {
  std::copy(srcs, srct, dsts);
  if (srct - srcs < dstt - dsts) std::fill(dsts + (srct - srcs), dstt, 0);
}
void polyinv(const int* const& F, int* const& invF, const int& n) {
  std::fill(invF, invF + n, 0);
  static int* const& inv_tmp = tmp[0];
  invF[0] = fpow(F[0], p - 2);
  int cb = 0;
  for (; (1 << cb) <= n; ++cb)
    ;
  if (n == (1 << --cb)) --cb;
  for (int deg = 4; ~cb; --cb, deg += deg) {
    const int cn = (n + (1 << cb) - 1) >> cb;
    cp(F, F + cn, inv_tmp, inv_tmp + deg);
    DFT(inv_tmp, deg);
    DFT(invF, deg);
    for (int i = 0; i != deg; ++i)
      invF[i] = (int64)invF[i] * sub(2ll, (int64)inv_tmp[i] * invF[i] % p) % p;
    IDFT(invF, deg);
    std::fill(invF + cn, invF + deg, 0);
  }
}
void polysqrt(const int* const& F, int* const& rt, int* const& invrt,
              const int& n) {
  static int *const &rt_tmp = tmp[0], *const &inv_tmp = tmp[1];
  if (n == 1) return (void)(rt[0] = invrt[0] = 1);
  const int m = (n + 1) >> 1;
  polysqrt(F, rt, invrt, m);
  int deg = 1;
  for (; deg <= n + n + 3; deg += deg)
    ;
  DFT(invrt, deg);
  std::copy(invrt, invrt + deg, inv_tmp);
  cp(rt, rt + m, rt_tmp, rt_tmp + deg);
  DFT(rt_tmp, deg);
  for (int i = 0; i != deg; ++i)
    inv_tmp[i] =
        (int64)inv_tmp[i] * sub(2ll, (int64)inv_tmp[i] * rt_tmp[i] % p) % p;
  cp(F, F + n, rt_tmp, rt_tmp + deg);
  DFT(rt_tmp, deg);
  for (int i = 0; i != deg; ++i) inv_tmp[i] = (int64)inv_tmp[i] * rt_tmp[i] % p;
  IDFT(inv_tmp, deg);
  for (int i = m; i != n; ++i) rt[i] = inv_tmp[i] = div2(inv_tmp[i]);
  std::fill(inv_tmp + n, inv_tmp + deg, 0);
  DFT(inv_tmp, deg);
  for (int i = 0; i != deg; ++i)
    invrt[i] = (int64)invrt[i] * sub(2ll, (int64)invrt[i] * inv_tmp[i] % p) % p;
  IDFT(invrt, deg);
  std::fill(invrt + n, invrt + deg, 0);
}
int C[mxdg + 1], rt[mxdg + 1];
int main() {
  int n = io;
  const int m((int)io + 1);
  C[0] = 1;
  for (int i; n; --n)
    if ((i = io) < m) C[i] = 998244349;
  int dg = 1;
  for (; dg <= m + m + 3; dg += dg)
    ;
  init_omg(dg);
  polysqrt(C, rt, tmp[2], m);
  inc(rt[0], 1);
  polyinv(rt, C, m);
  for (int i = 1; i < m; ++i)
    printf("%d\n", C[i] <= hfp ? C[i] + C[i] : (C[i] + C[i] - p));
  return 0;
}
