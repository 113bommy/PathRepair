#include <bits/stdc++.h>
using namespace std;
int cnt[27];
int dp[3000][3000];
string s, ans;
int main() {
  cin >> s;
  int len = int(s.size());
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
    if (cnt[s[i] - 'a'] > 100) {
      for (int j = 0; j < 100; j++) cout << char(i + 'a');
      cout << endl;
      return 0;
    }
  int i, j;
  for (i = 1; i <= s.size(); i++)
    for (j = 1; j <= s.size(); j++) {
      if (s[i - 1] == s[len - j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  i--, j--;
  while (i > 0 && j > 0) {
    if (s[i - 1] == s[len - j]) {
      ans += s[i - 1];
      i--;
      j--;
    } else if (dp[i - 1][j] == dp[i][j])
      i--;
    else
      j--;
  }
  if (ans.size() > 100) {
    for (int i = 0; i < 50; i++) cout << ans[i];
    for (int i = 49; i >= 0; i--) cout << ans[i];
    cout << endl;
  } else
    cout << ans << endl;
  return 0;
}
