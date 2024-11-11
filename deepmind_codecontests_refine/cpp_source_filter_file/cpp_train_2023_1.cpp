#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, MOD = 1e9 + 7;
int dp[N][4];
char s[10100];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> (s + 1);
  int n = strlen(s + 1);
  if (s[n] == '2') {
    cout << 0;
    return 0;
  }
  dp[0][0] = 1;
  dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == '0') dp[i][0] = dp[i - 1][0];
    if (s[i] == '1') {
      dp[i][0] = dp[i - 1][2];
      dp[i][1] = dp[i - 1][0];
    }
    if (s[i] == '2') dp[i][1] = dp[i - 1][2];
    if (s[i] == '*') {
      dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
      dp[i][3] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
    }
    if (s[i] == '?') {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
      dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
      dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
      dp[i][3] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
    }
  }
  if (s[n] == '0')
    cout << dp[n - 1][0];
  else if (s[n] == '1')
    cout << dp[n - 1][2];
  else if (s[n] == '*')
    cout << (dp[n - 1][1] + dp[n - 1][3]) % MOD;
  else
    cout << (((dp[n - 1][0] + dp[n - 1][1]) % MOD + dp[n - 1][2]) % MOD +
             dp[n - 1][3]) %
                MOD;
}
