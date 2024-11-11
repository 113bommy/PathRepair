#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
int dp[MAXN][MAXN], ans[MAXN];
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    dp[i][i] = 1;
    if (i != 0 && s[i - 1] == s[i]) dp[i - 1][i] = 2;
  }
  for (int si = 3; si <= s.size(); si++) {
    for (int i = 0; i <= s.size() - si; i++) {
      int j = i + si - 1;
      int mid = i + (j - i) / 2 - (j - 1) % 2;
      if (s[i] == s[j] && dp[i + 1][j - 1] != 0) dp[i][j] = dp[i][mid] + 1;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      while (dp[i][j]) {
        ans[dp[i][j]]++;
        dp[i][j]--;
      }
    }
  }
  for (int i = 1; i <= s.size(); i++) printf("%d ", ans[i]);
}
