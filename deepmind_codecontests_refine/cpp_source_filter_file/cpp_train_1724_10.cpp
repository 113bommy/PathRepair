#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void in(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) f |= (c == '-'), c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ '0'), c = getchar();
  f ? x = -x : 0;
}
template <class T>
inline void out(T x, const char c = '\n') {
  static short st[30];
  short m = 0;
  if (x < 0) putchar('-'), x = -x;
  do st[++m] = x % 10, x /= 10;
  while (x);
  while (m) putchar(st[m--] | '0');
  putchar(c);
}
template <class T, class... Args>
inline void in(T &x, Args &...args) {
  in(x);
  in(args...);
}
template <class T, class... Args>
inline void out(const T &x, const Args &...args) {
  out(x, ' ');
  out(args...);
}
template <class T>
inline void prt(T a[], int n) {
  for (register int i = 0; i < n; ++i) out(a[i], i == n - 1 ? '\n' : ' ');
}
template <class T>
inline void clr(T a[], int n) {
  memset(a, 0, sizeof(T) * n);
}
template <class T>
inline void clr(T *a, T *b) {
  memset(a, 0, sizeof(T) * (b - a));
}
template <class T>
inline bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
namespace MOD_CALC {
const int md = 998244353, inv2 = (md + 1) / 2;
inline int add(const int a, const int b) {
  return a + b >= md ? a + b - md : a + b;
}
inline int sub(const int a, const int b) {
  return a - b < 0 ? a - b + md : a - b;
}
inline int mul(const int a, const int b) { return (long long)a * b % md; }
inline void inc(int &a, const int b) { (a += b) >= md ? a -= md : 0; }
inline void dec(int &a, const int b) { (a -= b) < 0 ? a += md : 0; }
inline int qpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) r = mul(r, a);
  return r;
}
inline int qpow(int a, int b, const int p) {
  int r = 1;
  for (; b; b >>= 1, a = (long long)a * a % p)
    if (b & 1) r = (long long)r * a % p;
  return r;
}
inline int mdinv(const int a) { return qpow(a, md - 2); }
template <class... Args>
inline int add(const int a, const int b, const Args &...args) {
  return add(add(a, b), args...);
}
template <class... Args>
inline int mul(const int a, const int b, const Args &...args) {
  return mul(mul(a, b), args...);
}
}  // namespace MOD_CALC
using namespace MOD_CALC;
namespace i207M {
int c = 5;
struct cpx {
  int x, y;
  cpx(const int _x, const int _y) { x = _x, y = _y; }
  cpx() {}
  inline friend cpx operator+(const cpx &a, const cpx &b) {
    return cpx(add(a.x, b.x), add(a.y, b.y));
  }
  inline friend cpx operator-(const cpx &a, const cpx &b) {
    return cpx(sub(a.x, b.x), sub(a.y, b.y));
  }
  inline friend cpx operator*(const cpx &a, const cpx &b) {
    return cpx(add(mul(a.x, b.x), mul(c, a.y, b.y)),
               add(mul(a.x, b.y), mul(a.y, b.x)));
  }
  inline cpx operator*(const int v) const { return cpx(mul(x, v), mul(y, v)); }
  inline cpx operator~() const {
    int t = mdinv(sub(mul(x, x), mul(c, y, y)));
    return cpx(mul(x, t), mul(md - y, t));
  }
  inline friend cpx operator/(const cpx &a, const cpx &b) { return a * (~b); }
};
inline cpx qpow(cpx a, long long b) {
  cpx r(1, 0);
  for (; b; b >>= 1, a = a * a)
    if (b & 1) r = r * a;
  return r;
}
int bi[505][505], s[505][505], ifac[505];
int solve(cpx A, cpx B, cpx C, cpx D, int K, long long n) {
  int ans = 0;
  cpx XX(1, 0), YY(1, 0);
  for (register int i = 0; i <= K; ++i, XX = XX * B, YY = YY * D) {
    int sum = 0;
    cpx X = XX, Y = YY;
    for (register int j = 0; j <= i; ++j, X = X * A / B, Y = Y * C / D) {
      cpx t = (qpow(X, n + 1) - cpx(1, 0)) / (X - cpx(1, 0)) * Y;
      if (X.x == 1 && X.y == 0) t = Y * ((n + 1) % md);
      inc(sum, mul(bi[i][j], t.x));
    }
    sum = mul(s[K][i], sum);
    if ((K - i) & 1)
      dec(ans, sum);
    else
      inc(ans, sum);
  }
  ans = mul(ans, ifac[K]);
  return ans;
}
void prework() {
  bi[0][0] = s[0][0] = 1;
  for (register int i = 1; i <= 501; ++i) {
    bi[i][0] = 1;
    for (register int j = 1; j <= i; ++j) {
      bi[i][j] = add(bi[i - 1][j - 1], bi[i - 1][j]);
      s[i][j] = add(s[i - 1][j - 1], mul(s[i - 1][j], i - 1));
    }
  }
  ifac[0] = 1;
  for (register int i = 1; i <= 501; ++i) ifac[i] = mul(ifac[i - 1], mdinv(i));
}
const int inv10 = mdinv(10);
cpx A(inv2, inv2), B(inv2, md - inv2), C(inv2, inv10), D(inv2, md - inv10);
signed main() {
  long long l, r;
  int k, ans;
  prework();
  in(k, l, r);
  ans = solve(A, B, C, D, k, r + 1);
  dec(ans, solve(A, B, C, D, k, l));
  out(ans);
  return 0;
}
}  // namespace i207M
signed main() {
  i207M::main();
  return 0;
}
