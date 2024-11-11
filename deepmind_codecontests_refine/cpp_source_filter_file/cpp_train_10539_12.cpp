#include <bits/stdc++.h>
using namespace std;
string s, t;
int md = 998244353;
int dp[3007][3007];
int main() {
  cin >> s >> t;
  int n = s.length(), m = t.length();
  for (int i = 0; i <= n; i++) dp[i][i] = 1;
  for (int len = 1; len <= n; len++) {
    char c = s[len - 1];
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      if (i >= m || t[i] == c) {
        dp[i][j] += dp[i + 1][j];
        dp[i][j] %= md;
      }
      if (j > m || t[j - 1] == c) {
        dp[i][j] += dp[i][j - 1];
        dp[i][j] %= md;
      }
    }
  }
  long long ans = 0;
  for (int i = m - 1; i <= n; i++) ans = (ans + dp[0][i]) % md;
  cout << ans;
  return 0;
}
