#include <bits/stdc++.h>
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
void swap(long long &a, long long &b) {
  long long tmp = a;
  a = b;
  b = tmp;
}
long long lowbit(long long &x) { return x & (-x); }
void read(long long &x) {
  x = 0;
  char ch = getchar(), c = ch;
  while (ch < '0' || ch > '9') c = ch, ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  if (c == '-') x = -x;
}
const long long INF = 0x3f3f3f3f;
const long long MAXN = 300000 + 10;
const long long MAXM = 10;
long long dp[MAXN][MAXM + 10], n, m, k, a[MAXN];
int main() {
  read(n), read(m), read(k);
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < m; ++j) dp[i][j] = -INF;
  dp[0][m - 1] = 0;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 0; j < m; ++j) {
      if (j == 0)
        dp[i][j] = max(dp[i - 1][m - 1] + a[i], a[i]) - k;
      else
        dp[i][j] = dp[i - 1][j - 1] + a[i];
      ans = max(ans, dp[i][j]);
    }
  printf("%I64d", ans);
  return 0;
}
