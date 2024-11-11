#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const long long mod = 1e9 + 7;
long long dp[2][320][320];
int n, m, x;
void Add(long long& a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
  return;
}
long long solve() {
  dp[0][0][0] = 1;
  int now = 1;
  register int i, l, r;
  for (i = 1; i <= m; i++, now ^= 1)
    for (l = 0; l <= n; l++)
      for (r = 0, dp[now][l][0] = 0; r <= l; r++, dp[now][l][r] = 0)
        if (i == x) {
          if (l) Add(dp[now][l][r], dp[now ^ 1][l - 1][r]);
          if (l && r) Add(dp[now][l][r], dp[now ^ 1][l - 1][r - 1]);
        } else {
          Add(dp[now][l][r], dp[now ^ 1][l][r]);
          if (l - 1 >= r) Add(dp[now][l][r], dp[now ^ 1][l - 1][r]);
          if (r) Add(dp[now][l][r], dp[now ^ 1][l][r - 1]);
          if (l && r) Add(dp[now][l][r], dp[now ^ 1][l - 1][r - 1]);
        }
  long long ret = dp[now][n][n];
  for (int i = 1; i <= n; i++) ret = (ret * i) % mod;
  return ret;
}
int main() {
  scanf("%d %d %d", &n, &m, &x);
  long long ans;
  if (n > m)
    ans = 0;
  else
    ans = solve();
  printf("%I64d\n", ans);
  return 0;
}
