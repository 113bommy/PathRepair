#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool f = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = 1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return f ? -x : x;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  putchar('\n');
}
void writep(long long x) {
  write(x);
  putchar(' ');
}
long long const N = 1e6 + 3;
long long const M = 5e3 + 3;
long long n, m, Mo, a[N], fac[M], P[M], f[M][M], dp[2][M];
signed main() {
  n = read();
  m = read();
  Mo = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  fac[0] = P[0] = 1;
  for (long long i = 1; i <= 3000; i++) fac[i] = fac[i - 1] * i % Mo;
  for (long long i = 1; i <= 3000 && i <= m; i++)
    P[i] = P[i - 1] * (m - i + 1) % Mo;
  f[1][1] = f[2][2] = 1;
  for (long long i = 3; i <= 3000; i++)
    for (long long j = 2; j <= i; j++)
      f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * (j - 1) % Mo) % Mo;
  for (long long i = 1; i <= min(m, a[1]); i++)
    dp[1][i] = f[a[1]][i] * P[i] % Mo;
  for (long long i = 2; i <= n; i++) {
    long long res = 0;
    for (long long j = 1; j <= min(m, a[i - 1]); j++)
      res = (res + dp[(i - 1) & 1][j]) % Mo;
    for (long long j = 1; j <= min(m, a[i]); j++) {
      dp[i & 1][j] = f[a[i]][j] * P[j] % Mo * res % Mo;
      if (j <= a[i - 1])
        dp[i & 1][j] = ((dp[i & 1][j] -
                         dp[(i - 1) & 1][j] * f[a[i]][j] % Mo * fac[j] % Mo) %
                            Mo +
                        Mo) %
                       Mo;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= min(a[n], m); i++) ans = (ans + dp[n & 1][i]) % Mo;
  writeln(ans);
  return 0;
}
