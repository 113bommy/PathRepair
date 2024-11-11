#include <bits/stdc++.h>
using namespace std;
const long long N = 2010;
const double eps = 1e-9;
inline long long read() {
  long long s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
void print(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
long long n, l, a[N], b[N], f[N], ot[N];
double dp[N];
inline bool Check(long long x) {
  for (register long long i = 1; i <= n; i++) {
    dp[i] = 2e9;
    for (register long long j = 0; j < i; j++) {
      double now = dp[j] - x * b[i] + sqrt(llabs(l - a[i] + a[j]));
      if (dp[i] > now) dp[i] = now, f[i] = j;
    }
  }
  return dp[n] > 0;
}
signed main() {
  n = read(), l = read();
  for (register long long i = 1; i <= n; i++) a[i] = read(), b[i] = read();
  double L, R;
  L = 0, R = 1e10;
  double res = 0;
  while (R - L > eps) {
    if (Check(((L + R) / 2)))
      res = ((L + R) / 2), L = ((L + R) / 2);
    else
      R = ((L + R) / 2);
  }
  Check(res);
  long long now = 0, x = n;
  while (x) ot[++now] = x, x = f[x];
  for (register long long i = now; i; i--) printf("%lld ", ot[i]);
  puts("");
  return 0;
}
