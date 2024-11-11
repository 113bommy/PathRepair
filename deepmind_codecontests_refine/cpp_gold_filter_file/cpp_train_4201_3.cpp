#include <bits/stdc++.h>
using namespace std;
int dp[100050][2];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (isupper(s[i])) {
      dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
      dp[i][1] = dp[i - 1][1];
    } else {
      dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][1] + 1;
    }
  }
  cout << min(dp[s.length() - 1][0], dp[s.length() - 1][1]);
}
