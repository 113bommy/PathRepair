#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long cnt = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (isdigit(c)) {
    cnt = (cnt << 3) + (cnt << 1) + (c ^ 48);
    c = getchar();
  }
  return cnt * f;
}
const long long INF = (long long)1e18 + 7;
const long long N = (long long)1e5 + 10;
long long n, c, a[N], sum[N], dp[N], f[18][N];
void ST_prework() {
  for (register long long i = 1; i <= n; i++) f[0][i] = a[i];
  long long t = log(n) / log(2) + 1;
  for (register long long j = 1; j <= t; j++)
    for (register long long i = 1; i <= n - (1 << j) + 1; i++)
      f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
}
long long ST_query(long long l, long long r) {
  long long k = log(r - l + 1) / log(2);
  return min(f[k][l], f[k][r - (1 << k) + 1]);
}
signed main() {
  cin >> n >> c;
  for (register long long i = 1; i <= n; ++i)
    a[i] = read(), sum[i] = sum[i - 1] + a[i], dp[i] = INF;
  ST_prework();
  dp[0] = 0;
  for (register long long i = 1; i <= n; ++i) {
    if (i >= c)
      dp[i] =
          min(dp[i], dp[i - c] + sum[i] - sum[i - c] - ST_query(i - c + 1, i));
    dp[i] = min(dp[i], dp[i - 1] + a[i]);
  }
  printf("%lld", dp[n]);
  return 0;
}
