#include <bits/stdc++.h>
using namespace std;
int zero = 2001;
int64_t dp[2002][4004];
const int basic = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int bal = 0;
  int min_bal = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == '(')
      bal++;
    else
      bal--;
    min_bal = min(min_bal, bal);
  }
  dp[0][zero] = 1;
  for (int i = 1; i <= 2000; i++) {
    for (int j = zero + 1; j < 4002; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
      dp[i][j] %= basic;
    }
    dp[i][zero] = dp[i - 1][zero + 1];
  }
  int64_t ans = 0;
  int m = n - k;
  for (int i = 0; i <= m; i++) {
    for (int j = -min_bal; j <= i; j++) {
      if (zero + bal + j <= 2000) {
        int64_t res = dp[i][zero + j] * dp[m - i][zero + bal + j];
        res %= basic;
        ans += res;
        ans %= basic;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
