#include <bits/stdc++.h>
template <class T>
inline void read(T& x) {
  char c;
  bool f = 0;
  while ((c = getchar()) < '0' || '9' < c) f |= (c == '-');
  for (x = (c ^ 48); '0' <= (c = getchar()) && c <= '9';
       x = (x << 1) + (x << 3) + (c ^ 48))
    ;
  if (f) x = -x;
}
template <class T>
inline T read(const T sample) {
  T x = 0;
  char c;
  bool f = 0;
  while ((c = getchar()) < '0' || '9' < c) f |= (c == '-');
  for (x = (c ^ 48); '0' <= (c = getchar()) && c <= '9';
       x = (x << 1) + (x << 3) + (c ^ 48))
    ;
  return f ? -x : x;
}
template <class T>
void fwrit(const T x) {
  if (x < 0) return (void)(putchar('-'), fwrit(-x));
  if (x > 9) fwrit(x / 10);
  putchar(x % 10 ^ 48);
}
template <class T>
inline T Max(const T x, const T y) {
  return x > y ? x : y;
}
template <class T>
inline T Min(const T x, const T y) {
  return x < y ? x : y;
}
template <class T>
inline T fab(const T x) {
  return x > 0 ? x : -x;
}
inline int gcd(const int a, const int b) { return b ? gcd(b, a % b) : a; }
inline void getInv(int inv[], const int lim, const int MOD) {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= lim; ++i)
    inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
}
inline long long mulMod(const long long a, const long long b,
                        const long long mod) {
  return ((a * b - (long long)((long double)a / mod * b + 1e-8) * mod) % mod +
          mod) %
         mod;
}
const int MAXN = 3e5;
const int MOD = 998244353;
inline int Inv(int a, int n = MOD - 2) {
  int ret = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) ret = 1ll * ret * a % MOD;
    a = 1ll * a * a % MOD;
  }
  return ret;
}
struct edge {
  int to, nxt;
} e[MAXN * 2 + 5];
int tail[MAXN + 5], ecnt;
inline void add_edge(const int u, const int v) {
  e[++ecnt] = edge{v, tail[u]};
  tail[u] = ecnt;
  e[++ecnt] = edge{u, tail[v]};
  tail[v] = ecnt;
}
int n;
inline void Init() {
  n = read(1);
  for (signed i = (1), i_end_ = (n - 1); i <= i_end_; ++i)
    add_edge(read(1), read(1));
}
int f[MAXN + 5][3];
void Dfs(const int u, const int fa) {
  for (signed i = tail[u], v = e[i].to; i; i = e[i].nxt, v = e[i].to)
    if (v ^ fa) Dfs(v, u);
  f[u][0] = 0;
  f[u][1] = f[u][2] = 1;
  int pi = 1;
  for (signed i = tail[u], v = e[i].to; i; i = e[i].nxt, v = e[i].to)
    if (v ^ fa) pi = 1ll * pi * (f[v][0] * 2 + f[v][2]) % MOD;
  for (signed i = tail[u], v = e[i].to; i; i = e[i].nxt, v = e[i].to)
    if (v ^ fa) {
      f[u][0] += 1ll * (f[v][1] + f[v][2]) * pi % MOD *
                 Inv(f[v][0] * 2 % MOD + f[v][2]) % MOD;
      if (f[u][0] >= MOD) f[u][0] -= MOD;
    }
  for (signed i = tail[u], v = e[i].to; i; i = e[i].nxt, v = e[i].to)
    if (v ^ fa) f[u][2] = 1ll * f[u][2] * (f[v][0] + f[v][2]) % MOD;
  for (signed i = tail[u], v = e[i].to; i; i = e[i].nxt, v = e[i].to)
    if (v ^ fa) f[u][1] = 1ll * f[u][1] * (f[v][0] * 2 % MOD + f[v][2]) % MOD;
  f[u][1] = (f[u][1] - f[u][2] + MOD) % MOD;
}
signed main() {
  Init();
  Dfs(1, 0);
  fwrit((f[1][0] + f[1][2]) % MOD), putchar('\n');
  return 0;
}
