#include <bits/stdc++.h>
using namespace std;
inline void proc_status() {
  ifstream t("/proc/self/status");
  cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>())
       << endl;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline T read() {
  register T sum(0), fg(1);
  register char ch(getchar());
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fg = -1;
  for (; isdigit(ch); ch = getchar()) sum = sum * 10 - '0' + ch;
  return sum * fg;
}
const int MOD = 998244353;
namespace MATH {
const int MAXN = (int)3e3;
inline int fpm(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = (long long)x * x % MOD)
    if (y & 1) res = (long long)res * x % MOD;
  return res;
}
int inv[MAXN + 5], fac[MAXN + 5], ifac[MAXN + 5];
inline void init() {
  inv[1] = 1;
  for (int i = 2; i <= MAXN; ++i)
    inv[i] = (long long)MOD / i * -inv[MOD % i] % MOD;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= MAXN; ++i) {
    fac[i] = (long long)fac[i - 1] * i % MOD;
    ifac[i] = (long long)ifac[i - 1] * inv[i] % MOD;
  }
}
inline int C(int N, int M) {
  return N < M ? 0 : (long long)fac[N] * ifac[N - M] % MOD * ifac[M] % MOD;
}
inline int P(int N, int M) {
  return N < M ? 0 : (long long)fac[N] * ifac[N - M] % MOD;
}
}  // namespace MATH
using MATH::C;
using MATH::fac;
using MATH::fpm;
using MATH::ifac;
using MATH::inv;
using MATH::P;
namespace NTT {
const int MAX_LOG = 21, MAX_LEN = 1 << MAX_LOG;
int powg[MAX_LEN + 1], rev[MAX_LEN + 5], len, dis, inv_len;
inline void DFT_init(int N) {
  for (dis = 0, len = 1; len <= N; len <<= 1) ++dis;
  for (int i = 0; i < len; ++i)
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << (dis - 1);
  powg[0] = 1;
  for (int G = fpm(3, (MOD - 1) / len), i = 1; i <= len; ++i)
    powg[i] = (long long)powg[i - 1] * G % MOD;
  inv_len = fpm(len, MOD - 2);
}
inline void DFT(int *x, int type) {
  for (int i = 0; i < len; ++i)
    if (i < rev[i]) swap(x[i], x[rev[i]]);
  for (int k = 2; k <= len; k <<= 1)
    for (int j = 0; j < len; j += k)
      for (int i = 0; i < k / 2; ++i) {
        int G = type == 1 ? powg[len / k * i] : powg[len - len / k * i];
        int X = x[i + j], Y = (long long)x[i + j + k / 2] * G % MOD;
        x[i + j] = (X + Y) % MOD;
        x[i + j + k / 2] = (X - Y) % MOD;
      }
  if (type == -1)
    for (int i = 0; i < len; ++i) x[i] = (long long)x[i] * inv_len % MOD;
}
inline void mul(int *f, int N, int *g, int M, int *s) {
  if (N == 0) {
    for (int i = 0; i <= M; ++i) s[i] = (long long)g[i] * f[0] % MOD;
    return;
  }
  if (M == 0) {
    for (int i = 0; i <= N; ++i) s[i] = (long long)f[i] * g[0] % MOD;
    return;
  }
  static int F[(1 << MAX_LOG) + 5], G[(1 << MAX_LOG) + 5],
      S[(1 << MAX_LOG) + 5];
  DFT_init(N + M);
  for (int i = 0; i < len; ++i) F[i] = i <= N ? f[i] : 0;
  for (int i = 0; i < len; ++i) G[i] = i <= M ? g[i] : 0;
  DFT(F, +1);
  DFT(G, +1);
  for (int i = 0; i < len; ++i) S[i] = (long long)F[i] * G[i] % MOD;
  DFT(S, -1);
  for (int i = 0; i <= N + M; ++i) s[i] = S[i];
}
}  // namespace NTT
const int MAXN = (int)2e3;
int n, k, l;
inline void input() { n = read<int>(), k = read<int>(), l = read<int>(); }
inline void solve() {
  static int g[MAXN + 5];
  for (int i = 1; i <= n; ++i)
    g[i] = (long long)fpm(2, i) * fac[i] % MOD * fac[i] % MOD * ifac[2 * i] %
           MOD * inv[2 * i + 1] % MOD * C(n, i) % MOD;
  static int F[MAXN + 5], G[MAXN + 5], S[MAXN * 2 + 5];
  for (int i = 0; i <= n; ++i) {
    F[i] = (long long)g[i] * fac[i] % MOD;
    G[n - i] = (i & 1 ? -1 : +1) * ifac[i];
  }
  NTT::mul(F, n, G, n, S);
  int ans = 0;
  for (int i = k; i <= n; ++i)
    (ans += (long long)S[n + i] * ifac[i] % MOD) %= MOD;
  printf("%lld\n", 1ll * (ans + MOD) % MOD * l % MOD);
}
int main() {
  MATH::init();
  input();
  solve();
  return 0;
}
