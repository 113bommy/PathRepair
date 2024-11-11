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
  (b < a) && (a = b);
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
long long a[N], b[N];
int n;
long long calc(int g) {
  long long tmp = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    tmp = (tmp + b[i]) % g;
    ans += min(tmp, g - tmp);
  }
  return ans;
}
int main() {
  read(n);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) read(b[i]), sum += b[i];
  long long ans = 1e18;
  for (int i = 2; 1ll * i * i <= sum; ++i) {
    if (!(sum % i)) {
      chmin(ans, calc(i));
      while (!(sum % i)) sum /= i;
    }
  }
  if (sum > 1) chmin(ans, calc(sum));
  if (ans >= 1000000000000000000LL) ans = -1;
  printf("%lld\n", ans);
  return 0;
}
