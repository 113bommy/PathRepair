#include <bits/stdc++.h>
using namespace std;
int dp[4001][4001];
int main() {
  string s = "";
  string t = "";
  cin >> s >> t;
  for (int i = t.size(); i <= s.size(); i++) dp[i][0] += 1;
  if (s[s.size() - 1] == t[0]) dp[s.size() - 1][1] += 1;
  if (s.size() > t.size() || s[s.size() - 1] == t[s.size() - 1])
    dp[s.size() - 1][0] += 1;
  for (int i = s.size() - 1; i > 0; i--) {
    for (int j = 0; j <= s.size() - i; j++) {
      int pos1 = j;
      int pos2 = i + j - 1;
      if (pos1 >= t.size() || s[i - 1] == t[pos1]) {
        dp[i - 1][j + 1] = (dp[i][j] + dp[i - 1][j + 1]) % 998244353;
      }
      if (pos2 >= t.size() || s[i - 1] == t[pos2]) {
        dp[i - 1][j] = (dp[i][j] + dp[i - 1][j]) % 998244353;
      }
    }
  }
  int sum = 0;
  for (int j = 1; j <= s.size(); j++) {
    sum += dp[0][j];
    sum %= 998244353;
  }
  cout << sum;
  return 0;
}
