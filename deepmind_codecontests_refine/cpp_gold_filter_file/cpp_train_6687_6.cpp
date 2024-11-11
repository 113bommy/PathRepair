#include <bits/stdc++.h>
using namespace std;
const int N = 40;
long long R() {
  long long ans = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) ans = ans * 10 + c - '0';
  return ans * f;
}
long long dp[N][N], s[N], ans, P, n;
void Work() {
  memset(dp, 0, sizeof(dp));
  n = R();
  P = R();
  for (int i = 0; i <= 29; ++i) {
    int u = (1 << i), nx = min(n, (1ll << (i + 1)) - 1);
    if (u > n)
      s[i] = 0;
    else
      s[i] = nx - u + 1;
  }
  ans = 0;
  for (int i = 0; i <= 29; ++i) dp[1][i] = s[i], ans += s[i];
  ans %= P;
  for (int i = 2; i <= 33; ++i)
    for (int j = 0; j <= 29; ++j)
      for (int k = j + 1; k <= 29; ++k) {
        dp[i][k] += dp[i - 1][j] * s[k];
        dp[i][k] %= P;
        ans += dp[i - 1][j] * s[k];
        ans %= P;
      }
  cout << ans << '\n';
}
int main() {
  int t = R();
  while (t--) Work();
  return 0;
}
