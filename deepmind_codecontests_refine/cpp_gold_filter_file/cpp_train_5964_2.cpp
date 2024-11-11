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
const int N = 2e3 + 5;
int n, k, L[N], R[N], a[N];
long long dp[N], sum;
inline void calc(int &tot, int p, int &tim) {
  int _, a = ::a[p], L = ::L[p];
  if (a <= tot)
    tot -= a, tim = L;
  else
    _ = a - tot, tot = (k - (_ % k)) % k, tim = L + (_ / k - (_ % k == 0)) + 1;
}
inline void solve() {
  IN(n, k);
  for (int i = 1; i <= n; ++i) IN(L[i], R[i], a[i]), sum += a[i];
  dp[n + 1] = 0;
  for (int i = n; i >= 1; --i) {
    dp[i] = 1e18;
    int tot = k, tim;
    for (int j = i; j <= n; ++j) {
      calc(tot, j, tim);
      if (tim > R[j]) break;
      if (j == n) dp[i] = 0;
      if (L[j + 1] > tim) chkmin(dp[i], dp[j + 1] + tot);
    }
  }
  printf("%lld\n", dp[1] > 1e14 ? -1 : dp[1] + sum);
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
