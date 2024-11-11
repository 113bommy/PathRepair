#include <bits/stdc++.h>
using namespace std;
namespace SHENZHEBEI {
inline char gc() { return getchar(); }
inline long long read() {
  long long x = 0, f = 1;
  char ch = gc();
  for (; !isdigit(ch); ch = gc())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = gc()) x = x * 10 - 48 + ch;
  return x * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline char readchar() {
  char ch = gc();
  for (; isspace(ch); ch = gc())
    ;
  return ch;
}
inline long long readstr(char *s) {
  char ch = gc();
  int cur = 0;
  for (; isspace(ch); ch = gc())
    ;
  for (; !isspace(ch); ch = gc()) s[cur++] = ch;
  s[cur] = '\0';
  return cur;
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline double getreal() {
  static double lbc;
  scanf("%lf", &lbc);
  return lbc;
}
}  // namespace SHENZHEBEI
using namespace SHENZHEBEI;
const long long N = 210;
long long m, n, d, mod, c[N][N], f[N][N], g[N], ans;
int main() {
  n = read();
  m = read();
  mod = read();
  for (long long i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (long long j = 1; j <= i; ++j)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  f[1][0] = g[1] = 1;
  for (long long i = 2; i <= n; ++i) {
    for (long long j = 1; j < i; ++j)
      for (long long k = 1; k <= m; ++k)
        (f[i][j] =
             (f[i][j] + (f[i - j][k - 1] * g[j] % mod * c[i - 2][j - 1])) %
             mod);
    for (long long j = 0; j <= m - 1; ++j) (g[i] = (g[i] + (f[i][j])) % mod);
  }
  for (long long i = 0; i <= m; ++i)
    for (long long j = 0; j <= m - i; ++j)
      if (j != 1)
        for (long long k = 1; k <= n; ++k)
          (ans = (ans + (f[k][i] * f[n - k + 1][j])) % mod);
  writeln(2ll * n * (n - 1) % mod * ans % mod);
}
