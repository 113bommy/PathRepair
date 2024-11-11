#include <bits/stdc++.h>
const int inf = 1e9 + 7;
const int mod = 998244353;
namespace __________ {
namespace _in {
template <class T>
inline T read() {
  char ch;
  bool flag = 0;
  T x = 0;
  while (ch = getchar(), !isdigit(ch))
    if (ch == '-') flag = 1;
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  return flag ? -x : x;
}
struct {
  inline operator long long() { return read<long long>(); }
  inline operator int() { return read<int>(); }
  inline operator bool() { return read<bool>(); }
  template <class T>
  inline void operator()(T &x) {
    x = *this;
  }
  template <class T, class... A>
  inline void operator()(T &x, A &...a) {
    x = *this, this->operator()(a...);
  }
} IN;
}  // namespace _in
namespace _std {
template <class T>
inline T abs(T x) {
  if (x < 0) x = -x;
  return x;
}
template <class T>
inline T max(T x, T y) {
  if (x < y) x = y;
  return x;
}
template <class T>
inline T min(T x, T y) {
  if (x > y) x = y;
  return x;
}
template <class T>
inline void swap(T &x, T &y) {
  x ^= y ^= x ^= y;
}
template <class T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
template <class T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
}  // namespace _std
namespace _mod {
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int dec(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline void pls(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
inline int modpow(int x, int y, int res = 1) {
  if (y == -1) y = mod - 2;
  for (; y; y >>= 1, x = mul(x, x))
    if (y & 1) res = mul(res, x);
  return res;
}
}  // namespace _mod
using namespace _in;
using namespace _std;
using namespace _mod;
}  // namespace __________
using namespace __________;
const int N = 1e6 + 5;
int n, a[N], b[N], dp[N][2];
long long res, ans;
std::vector<int> son[N];
void dfs(int u, int fa) {
  dp[u][b[u]] = 1, res += b[u];
  for (int v : son[u])
    if (v != fa) {
      dfs(v, u);
      res += 1ll * dp[u][1] * dp[v][0];
      res += 1ll * dp[u][0] * dp[v][1];
      if (b[u])
        dp[u][1] += dp[v][0], dp[u][0] += dp[v][1];
      else
        dp[u][1] += dp[v][1], dp[u][0] += dp[v][0];
    }
}
inline void solve() {
  IN(n);
  for (int i = 1; i <= n; ++i) IN(a[i]);
  int u, v;
  for (int i = 2; i <= n; ++i)
    IN(u, v), son[u].push_back(v), son[v].push_back(u);
  for (int k = 0; k <= 20; ++k) {
    for (int i = 1; i <= n; ++i)
      b[i] = (a[i] >> k) & 1, dp[i][0] = dp[i][1] = 0;
    res = 0, dfs(1, 0), ans += 1ll * res * (1ll << k);
  }
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
