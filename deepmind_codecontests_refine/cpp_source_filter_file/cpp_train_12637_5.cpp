#include <bits/stdc++.h>
using namespace std;
const long long M = 100005;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, m, p, ls, q[M], d[M], s[M], T[M], dp[105][M];
double slope(long long x, long long y) {
  return 1.0 * (dp[ls][x] + s[x] - dp[ls][y] - s[y]) / (x - y);
}
signed main() {
  n = read();
  m = read();
  p = read();
  for (long long i = 2; i <= n; i++) d[i] = read() + d[i - 1];
  for (long long i = 1; i <= m; i++) {
    long long h = read();
    T[i] = read() - d[h];
  }
  sort(T + 1, T + 1 + m);
  for (long long i = 1; i <= m; i++) s[i] = s[i - 1] + T[i];
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  for (long long i = 1; i <= p; i++) {
    long long h = 0, t = 0;
    q[0] = 0;
    ls = i - 1;
    for (long long j = 1; j <= m; j++) {
      while (h < t && slope(q[h], q[h + 1]) < T[j]) h++;
      dp[i][j] = dp[ls][q[h]] + T[j] * (j - q[h]) - s[j] + s[q[h]];
      while (h < t && slope(q[t], q[t - 1]) > slope(i, q[t])) t--;
      q[++t] = j;
    }
  }
  printf("%lld\n", dp[p][m]);
}
