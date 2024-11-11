#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x7fffffffffffffff;
const double eps = 1e-10;
unsigned int seed = 19260817;
const unsigned int _RAND_MAX_ = 4294967295u;
__inline__ __attribute__((always_inline)) unsigned int Rand() {
  return seed = seed * 998244353u + 1000000007u;
}
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return (!b) ? a : gcd(b, a % b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp abs(const _Tp &a) {
  return a > 0 ? a : -a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp max(const _Tp &a, const _Tp &b) {
  return a < b ? b : a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp min(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmax(_Tp &a, const _Tp &b) {
  (a < b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmin(_Tp &a, const _Tp &b) {
  (a > b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) bool _cmp(const _Tp &a,
                                                    const _Tp &b) {
  return abs(a - b) <= eps;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void read(_Tp &x) {
  register char ch(getchar());
  bool f(false);
  while (ch < 48 || ch > 57) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (ch >= 48 && ch <= 57)
    x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
__inline__ __attribute__((always_inline)) int read_str(char *s) {
  register char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  register char *tar = s;
  *tar = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *(++tar) = ch, ch = getchar();
  return tar - s + 1;
}
const int N = 1000005;
const int mod = 998244353;
int a[N];
__inline__ __attribute__((always_inline)) void add(int &a, const int &b) {
  (a += b) >= mod && (a -= mod);
}
int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
  }
  int x = 1, mul = 1;
  int ans = 0;
  for (int i = n; i >= 1; --i) {
    add(ans, 1ll * x * a[i]);
    add(x, x);
    add(x, mul);
    add(mul, mul);
  }
  printf("%d\n", ans);
  return 0;
}
