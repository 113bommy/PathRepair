#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int dp[1000005][22][3], f[22][3];
int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int fpow(int x, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans *= x;
    x *= x;
    k >>= 1;
  }
  return ans;
}
int main() {
  int n = read(), x = floor(log(n) / log(2));
  dp[1][x][0] = 1;
  if (fpow(2, x - 1) * 3 <= n) dp[1][x - 1][1] = 1;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= 1; j++) {
      f[i][j] = n / fpow(2, i) / fpow(3, j);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k <= 1; k++) {
        dp[i + 1][j][k] =
            (dp[i + 1][j][k] + 1LL * dp[i][j][k] * (f[j][k] - i)) % p;
        if (j > 0)
          dp[i + 1][j - 1][k] = (dp[i + 1][j - 1][k] +
                                 1LL * dp[i][j][k] * (f[j - 1][k] - f[j][k])) %
                                p;
        if (k > 0)
          dp[i + 1][j][k - 1] = (dp[i + 1][j][k - 1] +
                                 1LL * dp[i][j][k] * (f[j][k - 1] - f[j][k])) %
                                p;
      }
    }
  }
  printf("%d\n", dp[n][0][0]);
  return 0;
}
