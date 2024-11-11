#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
inline long long read() {
  long long re = 0, k = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') k = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    re = re * 10 + ch - 48;
    ch = getchar();
  }
  return re * k;
}
inline void write(long long x) {
  if (x < 0) return putchar('-'), write(-x), void();
  if (x <= 9) return putchar(x + 48), void();
  return write(x / 10), write(x % 10), void();
}
long long n, f[3005][3005], a[5005], b[5005], g[3005][3005];
long long aabs(long long x) { return (x >= 0) ? x : -x; }
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    b[i] = a[i] = read() - i;
  }
  f[1][1] = 0;
  sort(b + 1, b + n + 1);
  for (long long i = 1; i <= n; i++) {
    g[i][0] = 0x3f3f3f3f;
    for (long long j = 1; j <= n; j++) {
      f[i][j] = g[i - 1][j] + aabs(a[i] - b[j]);
      g[i][j] = min(g[i][j - 1], f[i][j]);
    }
  }
  write(g[n][n]);
}
