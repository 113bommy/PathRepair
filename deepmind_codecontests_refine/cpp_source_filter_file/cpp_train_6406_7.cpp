#include <bits/stdc++.h>
const long long Mod = 1e9 + 7;
using namespace std;
char ch[10005];
long long dp[10005][2];
set<string> s;
int32_t main() {
  ch[0] = '#';
  scanf("%s", ch + 1);
  long long len = strlen(ch);
  dp[len][0] = 1, dp[len][1] = 1;
  for (long long i = len - 1; i >= 6; i--) {
    if (ch[i] == ch[i + 3] && ch[i + 1] == ch[i + 4]) {
      dp[i][0] = 0;
    } else {
      dp[i][0] |= dp[i + 2][0];
    }
    dp[i][0] |= dp[i + 2][1];
    if (ch[i] == ch[i + 3] && ch[i + 1] == ch[i + 4] &&
        ch[i + 2] == ch[i + 5]) {
      dp[i][0] = 0;
    } else {
      dp[i][1] |= dp[i + 3][1];
    }
    dp[i][1] |= dp[i + 3][0];
  }
  for (long long i = 6; i <= len - 1; i++) {
    string ss;
    ss += ch[i], ss += ch[i + 1];
    if (dp[i][0]) s.insert(ss);
    if (dp[i][1]) {
      ss += ch[i + 2];
      s.insert(ss);
    }
  }
  cout << s.size() << "\n";
  for (auto i = s.begin(); i != s.end(); i++) {
    cout << *i << "\n";
  }
}
