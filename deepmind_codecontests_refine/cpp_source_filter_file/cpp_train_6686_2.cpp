#include <bits/stdc++.h>
using namespace std;
template <class _Tp>
_Tp gcd(_Tp a, _Tp b) {
  return (b == 0) ? (a) : (gcd(b, a % b));
}
const long long Inf = 1000000000000000000ll;
const int inf = 1000000000;
char buf[1 << 25], *p1 = buf, *p2 = buf;
inline int getc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 25, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0, f = 0;
  char c = getc();
  while (!isdigit(c)) (c == '-') && (f = 1), c = getc();
  while (isdigit(c)) x = x * 10 + (c & 15), c = getc();
  return f ? -x : x;
}
const int N = 51;
const int M = 20005;
int n, m, k, a[N][M], s[N][M], sum[N][M], dp[N][M], q[M];
int main() {
  n = read();
  m = read();
  k = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) s[i][j] = s[i][j - 1] + a[i][j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) sum[i][1] += a[i][j];
    for (int j = 2; j + k - 1 <= m; ++j)
      sum[i][j] = sum[i][j - 1] - a[i][j - 1] + a[i][j + k - 1];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j + k - 1 <= m; ++j) sum[i][j] += sum[i + 1][j];
  for (int i = 1; i + k - 1 <= n; ++i) dp[1][i] = sum[1][i];
  for (int i = 2; i <= n; ++i) {
    int l = 1, r = 0, pre = 0;
    for (int j = 1; j + k - 1 <= m; ++j) {
      if (j - k >= 1) {
        pre = max(pre, dp[i - 1][j - k]);
        dp[i][j] = max(dp[i][j], pre + sum[i][j]);
      }
      while (l <= r && q[l] < j - k + 1) ++l;
      while (l <= r && dp[i - 1][q[r]] - s[i][q[r] + k - 1] <
                           dp[i - 1][j] - s[i][j + k - 1])
        --r;
      q[++r] = j;
      int cov = s[i][q[l] + k - 1] - dp[i - 1][q[l]];
      int x = s[i][j - 1] + sum[i][j];
      dp[i][j] = max(dp[i][j], x - cov);
    }
    int suf = 0;
    l = 1, r = 0;
    for (int j = m - k + 1; j; --j) {
      if (j + k + k - 1 <= m) {
        suf = max(suf, dp[i - 1][j + k]);
        dp[i][j] = max(dp[i][j], suf + sum[i][j]);
      }
      while (l <= r && q[l] > j + k - 1) ++l;
      while (l <= r &&
             dp[i - 1][q[r]] + s[i][q[r] - 1] < dp[i - 1][j] + s[i][j - 1])
        --r;
      q[++r] = j;
      int cov = -s[i][q[l] - 1] - dp[i - 1][q[l]];
      int x = -s[i][j + k - 1] + sum[i][j];
      dp[i][j] = max(dp[i][j], x - cov);
    }
  }
  int ans = 0;
  for (int i = 1; i + k - 1 <= m; ++i) ans = max(ans, dp[n][i]);
  printf("%d\n", ans);
  return 0;
}
