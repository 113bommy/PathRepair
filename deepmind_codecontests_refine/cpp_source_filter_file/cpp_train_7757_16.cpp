#include <bits/stdc++.h>
using namespace std;
const long long M = (long long)1e9 + 7;
const int N = (int)2e3 + 7;
long long dp[N][N];
void calc_dp() {
  dp[0][0] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j + 1 < N) dp[i][j] += dp[i - 1][j + 1];
      dp[i][j] %= M;
      if (j > 0) {
        dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] %= M;
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  calc_dp();
  int mn = 0, b = 0;
  for (auto x : s) {
    if (x == '(')
      ++b;
    else
      --b;
    mn = min(mn, b);
  }
  mn = -mn;
  long long ans = 0;
  for (int len = 0; len <= n - m; len++) {
    for (int bal = mn; bal <= len; bal++) {
      int len_q = n - len - m;
      int left_bal = bal + b;
      if (left_bal >= 0 && left_bal <= len)
        ans += dp[len][bal] * dp[len_q][left_bal];
      ans %= M;
    }
  }
  cout << ans;
  return 0;
}
