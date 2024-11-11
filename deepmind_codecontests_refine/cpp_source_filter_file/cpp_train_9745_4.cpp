#include <bits/stdc++.h>
using namespace std;
string s;
int n, dp[5010][5010];
int ans[5010];
int pal(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = (i == j || s[i] == s[j] && pal(i + 1, j - 1));
}
int main() {
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = 1;
    ans[1]++;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 2] = 1;
      ans[2]++;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      dp[i][j] = s[i] == s[j - 1] && dp[i + 1][j - 1];
      if (dp[i][j]) {
        int plen = len / 2;
        dp[i][j] = 1 + max(dp[i][i + plen], dp[j - plen][j]);
        ans[dp[i][j]]++;
      }
    }
  }
  for (int i = n - 1; i; i--) {
    ans[i] += ans[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    if (i != 1) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
