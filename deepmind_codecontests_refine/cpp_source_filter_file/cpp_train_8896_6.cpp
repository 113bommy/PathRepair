#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<long long int> > dp(n, vector<long long int>(2));
  if (s[0] == '0') {
    dp[0][0] = 0;
    dp[1][1] = 1;
  } else {
    dp[0][0] = 1;
    dp[0][1] = 0;
  }
  for (long long int i = 1; i < n; i++) {
    if (s[i] == '0') {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] + 1;
    } else {
      dp[i][0] = dp[i - 1][1] + 1;
      dp[i][1] = dp[i - 1][0];
    }
  }
  cout << min(dp[n - 1][0], dp[n - 1][1]);
  return 0;
}
