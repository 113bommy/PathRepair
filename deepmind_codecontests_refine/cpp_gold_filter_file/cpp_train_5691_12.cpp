#include <bits/stdc++.h>
using namespace std;
namespace _ {
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
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
  inline void operator()(T& x) {
    x = *this;
  }
  template <class T, class... A>
  inline void operator()(T& x, A&... a) {
    x = *this, this->operator()(a...);
  }
} IN;
}  // namespace _in
using namespace _in;
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
inline void pls(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void sub(int& x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
inline int modpow(int x, int y, int res = 1) {
  for (; y; y >>= 1, x = mul(x, x))
    if (y & 1) res = mul(res, x);
  return res;
}
}  // namespace _mod
using namespace _mod;
}  // namespace _
using namespace _;
const int N = 1e6 + 5;
int fac[N], inv[N];
inline int C(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return mul(fac[n], mul(inv[m], inv[n - m]));
}
inline int S(int n, int m) {
  int res = 0, tmp = 1;
  for (int i = 0; i <= m; ++i)
    pls(res, mul(mul(tmp, C(m, i)), modpow(m - i, n))), tmp = mod - tmp;
  return mul(inv[m], res);
}
int n, k, val[N];
int main() {
  IN(n, k), fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
  for (int i = 1; i <= n; ++i) inv[i] = modpow(fac[i], mod - 2);
  int res = 0;
  for (int i = 1; i <= n; ++i) IN(val[i]), pls(res, val[i]);
  printf("%d\n", mul(res, add(S(n, k), mul(n - 1, S(n - 1, k)))));
  return 0;
}
