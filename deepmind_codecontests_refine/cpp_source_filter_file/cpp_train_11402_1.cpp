#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 100005;
inline int read() {
  int res, ok = 1;
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') ok = -1;
  res = ch - '0';
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    res = res * 10 + ch - '0';
  return res * ok;
}
int n, a[205], m, now, pre;
long long ans, dp[2][205][1005];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  now = 0;
  pre = 1;
  dp[now][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    now ^= 1;
    pre ^= 1;
    memset(dp[now], 0, sizeof(dp[now]));
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= m; k++)
        if (dp[pre][j][k] != 0) {
          int sum = k + j * (a[i] - a[i - 1]);
          if (sum > m) continue;
          if (j)
            dp[now][j - 1][sum] =
                (dp[now][j - 1][sum] + dp[pre][j][k] * j % mod) % mod;
          dp[now][j + 1][sum] = (dp[now][j + 1][sum] + dp[pre][j][k]) % mod;
          dp[now][j][sum] =
              (dp[now][j][sum] + dp[pre][j][k] * (j + 1) % mod) % mod;
        }
  }
  for (int i = 0; i <= m; i++) ans = (ans + dp[now][0][i]);
  cout << ans << endl;
}
