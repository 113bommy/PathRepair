#include <bits/stdc++.h>
using namespace std;
const int MOD = 1E9 + 7;
const int N = 1E5 + 5;
int n, dp[N][3], pwr[N];
string s;
int main(int argc, char const *argv[]) {
  int c = 0;
  pwr[0] = 1;
  for (int i = 1; i < N; ++i) {
    pwr[i] = (3LL * pwr[i - 1]) % MOD;
  }
  cin >> n;
  cin >> s;
  if (s[0] == '?' || s[0] == 'a') dp[0][0] = 1;
  c += (s[0] == '?');
  for (int i = 1; i < n; ++i) {
    if (s[i] == '?') {
      dp[i][0] = (3LL * dp[i - 1][0] + pwr[c]) % MOD;
      dp[i][1] = (3LL * dp[i - 1][1] + 1LL * dp[i - 1][0]) % MOD;
      dp[i][2] = (3LL * dp[i - 1][2] + 1LL * dp[i - 1][1]) % MOD;
      c++;
    } else {
      if (s[i] == 'a')
        dp[i][0] = 1;
      else if (s[i] == 'b')
        dp[i][1] = dp[i - 1][0];
      else
        dp[i][2] = dp[i - 1][1];
      for (int j = 0; j < 3; ++j)
        dp[i][j] = (1LL * dp[i][j] + 1LL * dp[i - 1][j]) % MOD;
    }
  }
  cout << dp[n - 1][2] << '\n';
  return 0;
}
