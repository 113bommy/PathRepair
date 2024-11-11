#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 7;
const long long mod = 998244353;
int n, m;
string s1, s2;
long long dp[maxn][maxn];
int main() {
  cin >> s1 >> s2;
  n = s1.size();
  m = s2.size();
  for (int i = 0; i < m; i++) {
    if (s2[i] == s1[0]) dp[i][i + 2] = 1;
  }
  dp[m][m + 1] = 1;
  long long ans = dp[0][m + 1];
  for (int i = 1; i < n; i++) {
    for (int j = m; j >= 0; j--) {
      int d = min(i + 1, m + 1 - j);
      if (!dp[j][j + d]) continue;
      long long res = dp[j][j + d];
      dp[j][j + d] = 0;
      if (j != 0 && s2[j - 1] == s1[i])
        dp[j - 1][j + d] = (dp[j - 1][j + d] + res) % mod;
      if (j + d != m + 1 && s2[j + d - 1] == s1[i])
        dp[j][j + d + 1] = (dp[j][j + d + 1] + res) % mod;
      if (j + d == m + 1) dp[j][j + d] = (dp[j][j + d] + res) % mod;
      if (j == m) dp[j][j + d] = (dp[j][j + d] + res) % mod;
    }
    ans += dp[0][m + 1];
    ans %= mod;
  }
  cout << ans * 2 % mod << endl;
  return 0;
}
