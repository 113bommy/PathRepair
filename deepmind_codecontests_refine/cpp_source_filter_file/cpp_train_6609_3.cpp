#include <bits/stdc++.h>
using namespace std;
const long long N = 1005;
long long n, mn;
double p[N], f[N][N];
inline long long read() {
  long long ret = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = ret * 10 + (ch ^ 48);
    ch = getchar();
  }
  return ret * ff;
}
void write(long long x) {
  if (x < 0) {
    x = -x, putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
void writeln(long long x) { write(x), puts(""); }
void writesp(long long x) { write(x), putchar(' '); }
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    long long l = read(), r = read(), gs = 0;
    long long now = 1;
    for (long long j = 1; j <= 18; j++) {
      if (now * 2 - 1 < l) {
        now *= 10;
        continue;
      }
      if (now > r) break;
      gs += min(now * 2 - 1, r) - max(l, now) + 1;
      now *= 10;
    }
    p[i] = 1. * gs / (r - l + 1);
  }
  double K = 1. * read() / 100;
  for (long long i = 0; i <= n; i++) {
    if (i * 1. / n >= K) {
      mn = i;
      break;
    }
  }
  f[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    f[i][0] = f[i - 1][0] * (1. - p[i]);
    for (long long j = 1; j <= i; j++)
      f[i][j] = f[i - 1][j - 1] * p[i] + f[i - 1][j] * (1. - p[i]);
  }
  double ans = 0;
  for (long long i = mn; i <= n; i++) ans += f[n][i];
  printf("%.15lf", ans);
  return 0;
}
