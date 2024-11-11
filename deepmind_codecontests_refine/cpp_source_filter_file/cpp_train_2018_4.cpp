#include <bits/stdc++.h>
using namespace std;
namespace IO {
template <class T>
inline void readin(T& x) {
  char c;
  bool f = 0;
  while ((c = getchar()) < '0' || '9' < c) f |= (c == '-');
  for (x = (c ^ 48); '0' <= (c = getchar()) && c <= '9';
       x = (x << 1) + (x << 3) + (c ^ 48))
    ;
  if (f) x = -x;
}
template <class T>
inline T readin(T x) {
  x = 0;
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
  return x < y ? y : x;
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
}  // namespace IO
using namespace IO;
const int mod = 998244353;
const int maxm = 50;
const int maxn = 50;
double f[maxm + 5][maxn + 5][maxn + 5], C[maxn + 5][maxn + 5];
int n, m, a[maxm + 5];
inline void Init() {
  scanf("%d%d", &n, &m);
  for (signed i = (1), i_end_ = (m); i <= i_end_; ++i) scanf("%d", &a[i]);
  for (signed i = (0), i_end_ = (n); i <= i_end_; ++i) {
    C[i][0] = C[i][i] = 1;
    for (signed j = (1), j_end_ = (i - 1); j <= j_end_; ++j)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
}
inline void Get_f() {
  f[0][0][0] = 1;
  for (signed i = (1), i_end_ = (m); i <= i_end_; ++i)
    for (signed j = (0), j_end_ = (n); j <= j_end_; ++j)
      for (signed k = (0), k_end_ = (n); k <= k_end_; ++k)
        for (signed l = (0), l_end_ = (n - j); l <= l_end_; ++l)
          f[i][j + l][Max((l + a[i] - 1) / a[i], k)] +=
              f[i - 1][j][k] * C[n - j][l];
}
inline void Get_ans() {
  long long all = 0;
  for (signed i = (0), i_end_ = (n); i <= i_end_; ++i) all += f[m][n][i];
  double ans = 0;
  for (signed i = (1), i_end_ = (n); i <= i_end_; ++i)
    ans += i * f[m][n][i] * 1.0 / all;
  printf("%.20f\n", ans);
}
signed main() {
  Init();
  Get_f();
  Get_ans();
  return 0;
}
