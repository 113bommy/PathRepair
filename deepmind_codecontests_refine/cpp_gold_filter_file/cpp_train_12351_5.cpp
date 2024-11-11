#include <bits/stdc++.h>
using namespace std;
char ch;
long long read() {
  long long n = 0, p = 1;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') p = -1;
  for (; '0' <= ch && ch <= '9'; ch = getchar()) n = n * 10 + ch - '0';
  return n * p;
}
const long long N = 2010, mo = 998244353;
long long n;
long long qmi(long long x, long long n) {
  long long t = 1;
  for (x %= mo; n; n >>= 1, x = x * x % mo)
    if (n & 1) t = t * x % mo;
  return t;
}
long long g[N], f[N], cp[N][N], P[N], Q[N];
int main() {
  long long p, q;
  scanf("%d %I64d %I64d", &n, &p, &q);
  p = p * qmi(q, mo - 2) % mo;
  P[0] = Q[0] = 1;
  for (long long i = 1; i <= n; ++i)
    P[i] = P[i - 1] * p % mo, Q[i] = Q[i - 1] * (1 - p + mo) % mo;
  cp[0][0] = 1;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 0; j <= i; ++j)
      cp[i][j] =
          (j == 0)
              ? 1
              : (cp[i - 1][j] * Q[j] % mo + cp[i - 1][j - 1] * P[i - j] % mo) %
                    mo;
  g[1] = 1;
  for (long long i = 2; i <= n; ++i) {
    for (long long j = 1; j <= i - 1; ++j)
      g[i] = (g[i] + cp[i][j] * g[j] % mo) % mo;
    g[i] = (mo + 1 - g[i]) % mo;
  }
  for (long long i = 2; i <= n; ++i) {
    long long t = 0;
    for (long long j = 1; j <= i - 1; ++j) {
      long long x = (f[j] + f[i - j] + ((long long)j * (j - 1) / 2) % mo +
                     (long long)j * (i - j) % mo) %
                    mo;
      t = (t + x * g[j] % mo * cp[i][j] % mo) % mo;
    }
    t = (t + ((long long)i * (i - 1) / 2) % mo * g[i] % mo) % mo;
    f[i] = t * qmi(1 - g[i] + mo, mo - 2) % mo;
  }
  printf("%I64d", f[n]);
  return 0;
}
