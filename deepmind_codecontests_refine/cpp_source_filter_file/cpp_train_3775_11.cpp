#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x3f3f3f3f3f3f3f3f;
__inline__ __attribute__((always_inline)) unsigned int rnd() {
  static unsigned int seed = 416;
  return seed ^= seed >> 5, seed ^= seed << 17, seed ^= seed >> 13;
}
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return (!b) ? a : gcd(b, a % b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp abs(const _Tp &a) {
  return a >= 0 ? a : -a;
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
__inline__ __attribute__((always_inline)) void read(_Tp &x) {
  char ch(getchar());
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
  char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  char *tar = s;
  *tar = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *(++tar) = ch, ch = getchar();
  return tar - s + 1;
}
const int N = 300005;
const int mod = 998244353;
template <typename _Tp1, typename _Tp2>
__inline__ __attribute__((always_inline)) void add(_Tp1 &a, _Tp2 b) {
  (a += b) >= mod && (a -= mod);
}
template <typename _Tp1, typename _Tp2>
__inline__ __attribute__((always_inline)) void sub(_Tp1 &a, _Tp2 b) {
  (a -= b) < 0 && (a += mod);
}
long long ksm(long long a, long long b = mod - 2) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return res;
}
int n, a[N];
int sum[N];
int calc(int k) {
  long long ans = 0;
  for (int i = n - k, cur = 1; i >= 1; i -= k) {
    ans += 1ll * cur * (sum[i] - sum[max(i - k, 0)] + mod);
    ++cur;
  }
  return ans % mod;
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1], add(sum[i], a[i]);
  long long inv = ksm(n);
  for (int k = 1; k <= n; ++k) printf("%lld ", inv * calc(k) % mod);
  return 0;
}
