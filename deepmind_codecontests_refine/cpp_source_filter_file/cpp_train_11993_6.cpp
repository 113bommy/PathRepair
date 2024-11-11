#include <bits/stdc++.h>
long long mod = 1e9 + 7;
using namespace std;
int main() {
  string s;
  cin >> s;
  long long n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'm' || s[i] == 'w') {
      cout << 0 << endl;
      return 0;
    }
  }
  long long dp[n + 1];
  dp[0] = 1, dp[1] = 1;
  for (long long i = 2; i <= n; i++) {
    if (s[i - 2] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    } else
      dp[i] = dp[i - 1];
  }
  cout << dp[n] << endl;
  return 0;
}
