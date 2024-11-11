#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
inline void print(long long x) {
  if (x < 0) putchar('-'), x = ~x + 1;
  if (x >= 10) print(x / 10);
  putchar((x % 10) | 48);
}
long long n;
long long a[200010];
long long dp[200010][4][3];
void gmax(long long &x, long long y) { x = max(x, y); }
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  if (n == 1) {
    printf("%lld\n", a[1]);
    return 0;
  }
  memset(dp, -0x3f, sizeof(dp));
  dp[0][0][0] = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < 3; ++j) {
      for (long long k = 0; k < 2; ++k) {
        if (dp[i][j][k] > -0x151515153f3f3f3f) {
          gmax(dp[i + 1][(j + 1) % 3][k | ((j + 1) % 3 == 2)],
               dp[i][j][k] + a[i + 1]);
          gmax(dp[i + 1][(j + 2) % 3][k | ((j + 2) % 3 == 2)],
               dp[i][j][k] - a[i + 1]);
        }
      }
    }
  }
  printf("%lld\n", dp[n][1][1]);
}
