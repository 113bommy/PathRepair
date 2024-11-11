#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int dp[maxn][5];
set<string> ans;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (n <= 6) {
    printf("0\n");
    return 0;
  }
  if (n >= 7) {
    string s1 = "";
    s1 = s1 + s[n - 1] + s[n - 2];
    ans.insert(s1);
    dp[n - 2][2] = 1;
  }
  if (n >= 8) {
    string s1;
    s1 = s1 + s[n - 1] + s[n - 2] + s[n - 3];
    ans.insert(s1);
    dp[n - 3][3] = 1;
  }
  for (int i = n - 4; i >= 5; i--) {
    string s1 = "", s2 = "";
    s1 = s1 + s[i] + s[i + 1];
    s2 = s2 + s[i + 2] + s[i + 3];
    if ((s1 != s2 && dp[i + 2][2]) || dp[i + 2][3]) {
      dp[i][2] = 1;
      ans.insert(s1);
    }
    s1 = "";
    s2 = "";
    s1 = s1 + s[i] + s[i + 1] + s[i + 2];
    s2 = s2 + s[i + 3] + s[i + 4] + s[i + 5];
    if ((s1 != s2 && dp[i + 3][3]) || dp[i + 3][2]) {
      dp[i][3] = 1;
      ans.insert(s1);
    }
  }
  printf("%d\n", ans.size());
  for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
    cout << *it << endl;
  }
  return 0;
}
