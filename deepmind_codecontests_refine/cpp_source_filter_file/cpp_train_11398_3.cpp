#include <bits/stdc++.h>
const int M = 1005;
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
long long n, m, k, dp[M][105][2][2], pw[105];
long long dfs(long long x, long long s, long long ok, long long ze) {
  if (x == n) return ok;
  if (dp[x][s][ok][ze] != -1) return dp[x][s][ok][ze];
  long long tmp = 0;
  for (long long j = 0; j <= 9; j++) {
    if (j == 0 && x == n - 1) continue;
    long long ts = (s + j * pw[x]) % k, to = ok, tz = ze & (j == 0);
    if (!tz && ts == 0) to = 1;
    tmp = (tmp + dfs(x + 1, ts, to, tz)) % m;
  }
  return dp[x][s][ok][ze] = tmp;
}
signed main() {
  memset(dp, -1, sizeof dp);
  n = read();
  k = read();
  m = read();
  pw[0] = 1;
  for (long long i = 1; i <= n; i++) pw[i] = pw[i - 1] * 10 % k;
  printf("%lld\n", dfs(0, 0, 0, 1));
}
