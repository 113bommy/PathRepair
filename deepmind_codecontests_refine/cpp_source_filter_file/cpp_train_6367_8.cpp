#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[2][21][2];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
long long calc(int x, int y) {
  int now = (1 << x);
  if (y) now *= 3;
  return n / now;
}
int main() {
  n = read();
  int a = 0, b = 0;
  int tmp = 1;
  while ((tmp << 1) < n) {
    tmp <<= 1;
    a++;
  }
  tmp >>= 1;
  if (tmp * 3 <= n) dp[1][a - 1][1] = 1;
  dp[1][a][0] = 1;
  int now = 0, pre = 1;
  for (register int i = 2; i <= n; i++) {
    memset(dp[now], 0, sizeof(dp[now]));
    for (register int j = 0; j <= a; j++) {
      for (register int k = 0; k <= 1; k++) {
        dp[now][j][k] =
            (dp[now][j][k] + dp[pre][j][k] * (calc(j, k) - i + 1)) % 1000000007;
        if (j != a)
          dp[now][j][k] = (dp[now][j][k] +
                           dp[pre][j + 1][k] * (calc(j, k) - calc(j + 1, k))) %
                          1000000007;
        if (k != 1)
          dp[now][j][k] = (dp[now][j][k] +
                           dp[pre][j][k + 1] * (calc(j, k) - calc(j, k + 1))) %
                          1000000007;
      }
    }
    now ^= 1;
    pre ^= 1;
  }
  long long ans = (dp[pre][0][0] + 1000000007) % 1000000007;
  printf("%lld", ans);
  return 0;
}
