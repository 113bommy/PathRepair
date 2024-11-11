#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)2e18;
const int mod = 1e9 + 7;
bool overflow(long long int a, long long int b) {
  if (a <= (inf + b - 1) / b) return false;
  return true;
}
string s, t;
int nexty[405][26];
bool recurse(string t1, string t2) {
  int n = t1.length(), m = t2.length(), i, j;
  int dp[n + 2][m + 2];
  for (i = 0; i <= n; i++)
    for (j = 0; j <= m; j++) dp[i][j] = 1e9;
  dp[0][0] = 0;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      if (dp[i][j] < s.length()) {
        if (i < n)
          dp[i + 1][j] = min(dp[i + 1][j], nexty[dp[i][j]][t1[i] - 97] + 1);
        if (j < m)
          dp[i][j + 1] = min(dp[i][j + 1], nexty[dp[i][j]][t2[j] - 97] + 1);
      } else {
        dp[i + 1][j] = dp[i][j];
        dp[i][j + 1] = dp[i][j];
      }
    }
  }
  return dp[n][m] <= s.length();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int test;
  cin >> test;
  while (test--) {
    cin >> s >> t;
    int i, j, n = t.length();
    for (i = 0; i < 26; i++) {
      nexty[s.length()][i] = 1e9;
    }
    for (i = s.length() - 1; i >= 0; i--) {
      for (j = 0; j < 26; j++) nexty[i][j] = nexty[i + 1][j];
      nexty[i][s[i] - 97] = i;
    }
    for (i = 0; i <= n; i++) {
      if (recurse(t.substr(0, i), t.substr(i, t.length() - i))) break;
    }
    if (i <= n) {
      cout << "YES"
           << "\n";
    } else
      cout << "NO"
           << "\n";
  }
}
