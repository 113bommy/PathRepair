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
int n, m, s[N], t[N], p[N], S[N], T[N], sta[30];
const int LogN = 21;
int tim, lim, inv;
std::vector<int> rev, w[LogN];
inline void init_w(int lim = 1 << 19) {
  w[19].resize(lim), w[19][0] = 1, w[19][1] = modpow(3, (mod - 1) >> 20);
  for (int i = 2; i < lim; ++i) w[19][i] = mul(w[19][i - 1], w[19][1]);
  for (int i = 18; ~i; --i) {
    w[i].resize(lim >>= 1);
    for (int j = 0; j < lim; ++j) w[i][j] = w[i + 1][j << 1];
  }
}
inline void init_r(int len) {
  for (lim = 1, tim = 0; lim < len; lim <<= 1, ++tim)
    ;
  rev.resize(lim), inv = modpow(lim, mod - 2);
  for (int i = 0; i < lim; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (tim - 1));
}
inline void NTT(std::vector<int> &f, int typ) {
  static unsigned long long g[1 << 20 | 5];
  for (int i = 0; i < lim; ++i) g[rev[i]] = f[i];
  for (int p = 1, s = 0, t = 0; p < lim; p <<= 1, ++t)
    for (int k = 0; k < lim; k += p << 1)
      for (int l = k; l < k + p; ++l)
        s = mul(g[l + p] % mod, w[t][l - k]), g[l + p] = g[l] + mod - s,
        g[l] += s;
  for (int i = 0; i < lim; ++i) f[i] = g[i] % mod;
  if (~typ) return;
  std::reverse(++f.begin(), f.end());
  for (int i = 0; i < lim; ++i) f[i] = mul(f[i], inv);
}
std::vector<int> s1, s2, f, g;
inline void init() {
  init_r(n + m + 2);
  f.resize(lim), g.resize(lim);
  for (int i = 0; i <= lim - 1; ++i) f[i] = S[i];
  NTT(f, 1);
  for (int i = 0; i <= lim - 1; ++i) g[i] = t[i];
  NTT(g, 1);
  s1.resize(lim);
  for (int i = 0; i <= lim - 1; ++i) s1[i] = mul(f[i], g[i]);
  NTT(s1, -1);
  for (int i = 0; i <= lim - 1; ++i) f[i] = s[i];
  NTT(f, 1);
  for (int i = 0; i <= lim - 1; ++i) g[i] = T[i];
  NTT(g, 1);
  s2.resize(lim);
  for (int i = 0; i <= lim - 1; ++i) s2[i] = mul(f[i], g[i]);
  NTT(s2, -1);
}
int res, sum[N];
inline void solve() {
  for (int i = 1; i <= n; ++i) pls(res, mul(S[i], s[i]));
  for (int i = 1; i <= m; ++i) sum[i] = add(sum[i - 1], mul(T[i], t[i]));
  for (int i = 1; i <= m - n + 1; ++i) {
    int has = add(res, dec(sum[i + n - 1], sum[i - 1]));
    sub(has, add(s1[n + i], s2[n + i]));
    putchar(has > 0 ? '0' : '1');
  }
}
char str[N];
int main() {
  init_w();
  srand(991882), srand(rand());
  for (int i = 1; i <= 26; ++i) sta[i] = add(1, rand() % mod);
  for (int i = 1; i <= 26; ++i) IN(p[i]);
  scanf("%s", str + 1), n = strlen(str + 1);
  for (int i = 1; i <= n; ++i) s[i] = str[i] - 'a' + 1;
  scanf("%s", str + 1), m = strlen(str + 1);
  for (int i = 1; i <= m; ++i) t[i] = str[i] - 'a' + 1;
  for (int i = 1; i <= n; ++i) S[i] = sta[s[i]], s[i] = p[s[i]];
  for (int i = 1; i <= m; ++i) T[i] = sta[t[i]];
  std::reverse(s + 1, s + 1 + n), std::reverse(S + 1, S + 1 + n);
  init(), solve(), puts("");
  return 0;
}
