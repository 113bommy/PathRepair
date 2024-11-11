#include <bits/stdc++.h>
namespace ztd {
using namespace std;
template <typename T>
inline T read(T& t) {
  t = 0;
  short f = 1;
  char ch = getchar();
  double d = 0.1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t *= f;
  return t;
}
const int mod = 1e9 + 7;
inline long long ksm(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return ret;
}
inline long long inv(long long x) { return ksm(x, mod - 2); }
}  // namespace ztd
using namespace ztd;
const int maxn = 1e6 + 7;
int n;
long long fact[maxn], finv[maxn], f[maxn];
inline void pre(int uplimit) {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= uplimit; ++i) fact[i] = fact[i - 1] * i % mod;
  finv[uplimit] = ksm(fact[uplimit], mod - 2);
  for (int i = uplimit - 1; i >= 0; --i) finv[i] = finv[i + 1] * (i + 1) % mod;
  finv[0] = 1;
  f[0] = 1;
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= uplimit; ++i)
    f[i] = (f[i - 1] + (i - 1) * f[i - 2] % mod) % mod;
}
signed main() {
  pre(1e6 + 2);
  read(n);
  int cnt = 0, lkyakioi;
  for (int i = 1; i <= n; ++i)
    if (read(lkyakioi) == 1) ++cnt;
  cout << fact[n] * finv[cnt] % mod * f[cnt] % mod << '\n';
  return 0;
}
