#include <bits/stdc++.h>
using std::max;
using std::min;
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x3f3f3f3f3f3f3f3f;
__inline__ __attribute__((always_inline)) unsigned int rnd() {
  static unsigned int seed = 416;
  return seed += 0x71dad4bfu, seed ^= seed >> 5, seed += 0xc6f74d88u,
         seed ^= seed << 17, seed += 0x25e6561u, seed ^= seed >> 13;
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
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  f && (x = -x);
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) _Tp min(const _Tp &a, const _Tp &b,
                                                  const Args &...args) {
  return a < b ? min(a, args...) : min(b, args...);
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) _Tp max(const _Tp &a, const _Tp &b,
                                                  const Args &...args) {
  return a < b ? max(b, args...) : max(a, args...);
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
const int N = 3505;
const int mod = 1000000007;
template <typename _Tp1, typename _Tp2>
__inline__ __attribute__((always_inline)) void add(_Tp1 &a, _Tp2 b) {
  (a += b) >= mod && (a -= mod);
}
template <typename _Tp1, typename _Tp2>
__inline__ __attribute__((always_inline)) void sub(_Tp1 &a, _Tp2 b) {
  (a -= b) < 0 && (a += mod);
}
char t[N];
int s[N], b[N], p, a;
int dp[N][N][2][2];
__inline__ __attribute__((always_inline)) long long f(long long x) {
  return (x * (x + 1) >> 1) % mod;
}
int dfs(int pos, int cnt, bool limit, bool need) {
  if (!pos) return !need && cnt >= a;
  if (~dp[pos][cnt][need][limit]) return dp[pos][cnt][need][limit];
  int maxx = limit ? b[pos] : p - 1, ans = 0;
  if (!need) {
    add(ans, 1ll * dfs(pos - 1, cnt, false, 0) * f(maxx) % mod);
    add(ans, 1ll * dfs(pos - 1, cnt, limit, 0) * (maxx + 1) % mod);
    add(ans, 1ll * dfs(pos - 1, cnt + 1, false, 1) * f(maxx - 1) % mod);
    add(ans, 1ll * dfs(pos - 1, cnt + 1, limit, 1) * maxx % mod);
  } else {
    add(ans, 1ll * dfs(pos - 1, cnt, false, 0) *
                 (f(p - 1) - f(p - maxx - 1) + mod) % mod);
    add(ans, 1ll * dfs(pos - 1, cnt, limit, 0) * (p - 1 - maxx) % mod);
    add(ans, 1ll * dfs(pos - 1, cnt + 1, false, 1) *
                 (f(p) - f(p - maxx) + mod) % mod);
    add(ans, 1ll * dfs(pos - 1, cnt + 1, limit, 1) * (p - maxx) % mod);
  }
  dp[pos][cnt][need][limit] = ans;
  return ans;
}
int main() {
  memset(dp, 255, sizeof(dp));
  read(p, a);
  int len = read_str(t);
  for (int i = 0; i < len; ++i) s[i] = t[i] - 48;
  std::reverse(s, s + len);
  int pos = 0;
  while (len > 0 || s[0]) {
    int tmp = 0;
    for (int i = len - 1; i >= 0; --i) tmp = (tmp * 10 + s[i]) % p;
    b[++pos] = tmp % p;
    tmp = 0;
    for (int i = len - 1; i >= 0; --i) {
      tmp = tmp * 10 + s[i];
      s[i] = tmp / p;
      tmp %= p;
    }
    while (len > 0 && !s[len - 1]) --len;
  }
  printf("%d\n", dfs(pos, 0, 1, 0));
  return 0;
}
