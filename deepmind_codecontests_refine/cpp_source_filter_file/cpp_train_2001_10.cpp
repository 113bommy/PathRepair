#include <bits/stdc++.h>
using namespace std;
int dp[26];
vector<int> ans;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  memset(dp, -1, sizeof(dp));
  int len = 0;
  for (int i = 0; i < str.size(); i++) {
    int c = str[i] - 97;
    for (int j = 0; j < 26; j++) {
      if (c > dp[j]) {
        len = max(len, j + 1);
        dp[j] = c;
        ans.push_back(j + 1);
        break;
      }
    }
  }
  cout << len << "\n";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
