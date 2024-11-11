#include <bits/stdc++.h>
clock_t t = clock();
namespace my_std {
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T rnd(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &t) {
  t = 0;
  char f = 0, ch = getchar();
  double d = 0.1;
  while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') t = t * 10 + ch - 48, ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t = (f ? -t : t);
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
char __sr[1 << 21], __z[20];
int __C = -1, __zz = 0;
inline void Ot() { fwrite(__sr, 1, __C + 1, stdout), __C = -1; }
inline void print(register int x) {
  if (__C > 1 << 20) Ot();
  if (x < 0) __sr[++__C] = '-', x = -x;
  while (__z[++__zz] = x % 10 + 48, x /= 10)
    ;
  while (__sr[++__C] = __z[__zz], --__zz)
    ;
  __sr[++__C] = '\n';
}
void file() {}
inline void chktime() {}
long long ksm(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) ret = ret * x;
  return ret;
}
}  // namespace my_std
using namespace my_std;
const int m = 50;
int n;
long double p;
long double P[3333], pp[3333];
void work(long double *F, long double *G, int n) {
  static long double f[3333][m + 5], g[3333][m + 5];
  memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
  for (int i = (1); i <= (min(m, n + 1)); i++) f[1][i] = F[i], g[1][i] = G[i];
  for (int i = (2); i <= (n); i++)
    for (int j = (1); j <= (min(n - i + 2, m)); j++) {
      for (int k = (j + 1); k <= (m); k++) {
        long double w = (j == n - i + 2 ? pp[j] : P[j]);
        if (i == n) w = (j == 1 ? p : 1 - p);
        f[i][j] += f[i - 1][k] * w;
        g[i][j] += w * (g[i - 1][k] + f[i - 1][k] * j);
      }
      long double w;
      if (j == 2)
        w = 1 - p;
      else if (j == 1)
        w = 0;
      else if (j != n - i + 2)
        w = pp[j];
      else
        w = pp[j - 1] * pp[j - 1];
      f[i][j] += f[i - 1][1] * w;
      g[i][j] += w * (g[i - 1][1] + f[i - 1][1] * j);
    }
  long double ans = 0;
  for (int i = (1); i <= (m); i++) ans += g[n][i];
  cout << setprecision(17) << ans << '\n';
}
long double f[3333][m + 5], g[3333][m + 5], tmp1[m + 5], tmp2[m + 5];
int main() {
  file();
  read(n, p), p /= 1e9;
  if (n == 1) return cout << setprecision(17) << p + 2 * (1 - p) << '\n', 0;
  P[1] = p, P[2] = 1 - p + p * p;
  for (int i = (3); i <= (m); i++) {
    P[i] = P[i - 1] * P[i - 1];
    if (P[i] < 1e-12) break;
  }
  pp[2] = 1 - p;
  for (int i = (3); i <= (m); i++) {
    pp[i] = pp[2];
    for (int j = (2); j <= (i - 1); j++) pp[i] *= P[j];
    if (pp[i] < 1e-12) break;
  }
  for (int i = (1); i <= (min(m, n)); i++) f[1][i] = P[i], g[1][i] = P[i] * i;
  if (n + 1 <= m) f[1][n + 1] = pp[n + 1], g[1][n + 1] = pp[n + 1] * (n + 1);
  if (n <= 2000) return work(tmp1, tmp2, n), 0;
  for (int i = (2); i <= (1500); i++)
    for (int j = (1); j <= (m); j++) {
      for (int k = (j + 1); k <= (m); k++) {
        long double w = P[j];
        f[i][j] += f[i - 1][k] * w;
        g[i][j] += w * (g[i - 1][k] + f[i - 1][k] * j);
      }
      long double w = pp[j];
      f[i][j] += f[i - 1][1] * w;
      g[i][j] += w * (g[i - 1][1] + f[i - 1][1] * j);
    }
  int nn = n - 1500 - 100;
  for (int i = (1); i <= (m); i++) tmp1[i] = f[1500][i];
  for (int i = (1); i <= (m); i++)
    tmp2[i] = g[1500][i] + (g[1500][i] - g[1499][i]) * nn;
  work(tmp1, tmp2, 101);
  return 0;
}
