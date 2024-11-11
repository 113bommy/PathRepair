#include <bits/stdc++.h>
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
long long n, ans, a[M], dp[M][20], f[M];
long long Min(long long x, long long y) { return a[x] < a[y] ? x : y; }
long long ask(long long l, long long r) {
  long long k = log2(r - l + 1);
  return Min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
signed main() {
  n = read();
  for (long long i = 1; i < n; i++) {
    a[i] = read();
    dp[i][0] = i;
  }
  for (long long j = 1; (1 << j) <= n; j++)
    for (long long i = 1; i + (1 << j) - 1 <= n; i++)
      dp[i][j] = Min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
  for (long long i = n - 1; i >= 1; i--) {
    long long k = ask(i + 1, a[i]);
    if (a[i] >= n)
      f[i] = n - i;
    else
      f[i] = f[k] + (n - i) - (a[i] - k);
    ans += f[i];
  }
  printf("%lld\n", ans);
}
