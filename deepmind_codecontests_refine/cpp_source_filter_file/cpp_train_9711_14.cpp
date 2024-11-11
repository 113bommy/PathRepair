#include <bits/stdc++.h>
using std::max;
using std::min;
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x3f3f3f3f3f3f3f3f;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return (!b) ? a : gcd(b, a % b);
}
template <typename _Tp>
inline _Tp abs(const _Tp &a) {
  return a >= 0 ? a : -a;
}
template <typename _Tp>
inline void chmax(_Tp &a, const _Tp &b) {
  (a < b) && (a = b);
}
template <typename _Tp>
inline void chmin(_Tp &a, const _Tp &b) {
  (b < a) && (a = b);
}
template <typename _Tp>
inline void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  f && (x = -x);
}
template <typename _Tp, typename... Args>
inline void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
inline int read_str(char *s) {
  char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  char *tar = s;
  *tar = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *(++tar) = ch, ch = getchar();
  return tar - s + 1;
}
const int N = 1000005;
long long dp[N], _[N];
int main() {
  int k;
  read(k), k = 3 * (k - 1);
  int mul = 1;
  memset(dp, -63, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < 6; ++i) {
    int tmp = k, t = 1, x;
    read(x);
    memset(_, -63, sizeof(_));
    for (int v = 0; v < 10; ++v) {
      long long cost = 1ll * mul * v, w = v % 3 == 0 ? (v / 3) * x : 0;
      for (int i = 0; i + cost < N; ++i) chmax(_[i + cost], dp[i] + w);
    }
    memcpy(dp, _, sizeof(dp));
    while (tmp > t) {
      tmp -= t;
      long long cost = 1ll * mul * 3 * t, w = 1ll * x * t;
      if (cost < N)
        for (int i = N - cost - 1; i >= 0; --i) chmax(dp[i + cost], dp[i] + w);
      t <<= 1;
    }
    long long cost = 1ll * mul * 3 * tmp, w = 1ll * x * tmp;
    if (cost < N)
      for (int i = N - cost - 1; i >= 0; --i) chmax(dp[i + cost], dp[i] + w);
    mul = mul * 10;
  }
  int q, x;
  read(q);
  while (q--) {
    read(x);
    printf("%lld\n", dp[x]);
  }
  return 0;
}
