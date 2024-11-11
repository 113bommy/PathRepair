#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  bool dp[len + 2][2];
  memset(dp, false, sizeof(dp));
  dp[len][0] = dp[len][1] = true;
  set<string> ans;
  for (int i = len - 2; i > 4; --i) {
    if ((dp[i + 2][0] && s.substr(i, 2) != s.substr(i + 2, 2)) ||
        dp[i + 2][1]) {
      ans.insert(s.substr(i, 2));
      dp[i][0] = true;
    }
    if ((dp[i + 3][1] && s.substr(i, 3) != s.substr(i + 3, 3)) ||
        dp[i + 3][1]) {
      ans.insert(s.substr(i, 3));
      dp[i][1] = true;
    }
  }
  if (ans.empty()) {
    cout << 0 << endl;
    return 0;
  }
  cout << ans.size() << endl;
  set<string>::iterator iterator1 = ans.begin();
  for (; iterator1 != ans.end(); iterator1++) {
    cout << *iterator1 << endl;
  }
}
