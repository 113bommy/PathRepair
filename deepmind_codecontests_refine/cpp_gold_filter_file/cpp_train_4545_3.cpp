#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  cin >> str;
  int n = str.size();
  vector<string> dp(n);
  dp[0] = str;
  int c = 1;
  while (c < n) c *= 2;
  c /= 2;
  for (int i = 1; i < c; i++) {
    string pre = "";
    for (int bit = 0; (1 << bit) <= i; bit++) {
      if (((1 << bit) & i) == 0) continue;
      int len = dp[i ^ (1 << bit)].size() - (1 << bit);
      string te = dp[i ^ (1 << bit)].substr(0, len);
      if (pre.size())
        pre = min(dp[i ^ (1 << bit)], pre);
      else
        pre = dp[i ^ (1 << bit)];
    }
    bool bo = false;
    for (int j = i; j < n; j++) {
      if (str[j] < pre[j - i]) bo = true;
      if (bo) {
        dp[i].push_back(str[j]);
      } else {
        dp[i].push_back(pre[j - i]);
      }
    }
  }
  cout << dp[max(0, c - 1)] << "\n";
  return 0;
}
