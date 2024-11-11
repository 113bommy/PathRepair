#include <bits/stdc++.h>
using namespace std;
long long INF = (long long)1e20;
long long mod = (long long)1e9 + 7;
long long iINF = (int)1e20;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
long long dp[4100][4100];
long long c[2001][2001];
long long calc(long long open, long long close) {
  if (open == 0 && close == 0) {
    dp[open + close][open - close] = 1;
    return dp[open + close][open - close];
  }
  if (close > open || close < 0) {
    return 0;
  }
  if (dp[open + close][open - close] != 0) {
    return dp[open + close][open - close];
  }
  dp[open + close][open - close] =
      (calc(open, close - 1) + calc(open - 1, close)) % mod;
  return dp[open + close][open - close];
}
signed main() {
  long long n, m;
  cin >> n >> m;
  int bal = 0, min_bal = 0;
  for (int i = 0; i < m; ++i) {
    char c;
    cin >> c;
    if (c == '(') {
      ++bal;
    } else {
      --bal;
    }
    min_bal = min(min_bal, bal);
  }
  fill(&dp[0][0], &dp[0][0] + 4100 * 4100, 0);
  long long num = calc(2001, 2001);
  c[1][0] = 1;
  c[1][1] = 1;
  c[0][0] = 1;
  for (int i = 2; i < 2001; ++i) {
    c[i][0] = 1;
    c[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= (n - m); ++i) {
    for (int b = -min_bal; b <= i; ++b) {
      if (n - m - i >= b + bal) {
        ans += (dp[i][b] * dp[n - m - i][b + bal]) % mod;
        ans %= mod;
      }
    }
  }
  cout << ans;
}
