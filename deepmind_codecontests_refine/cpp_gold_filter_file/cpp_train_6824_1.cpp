#include <bits/stdc++.h>
int64_t M = 1e9 + 7;
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto& i : c) cin >> i;
    vector<string> s(n), r(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      r[i] = s[i];
      reverse(r[i].begin(), r[i].end());
    }
    int64_t dp[100001][2];
    dp[0][0] = 0;
    dp[0][1] = c[0];
    int i;
    for (i = 1; i < n; i++) {
      dp[i][0] = 1e18;
      dp[i][1] = 1e18;
      if (s[i] >= s[i - 1] && dp[i - 1][0] != 1e18)
        dp[i][0] = min(dp[i][0], dp[i - 1][0]);
      if (s[i] >= r[i - 1] && dp[i - 1][1] != 1e18)
        dp[i][0] = min(dp[i][0], dp[i - 1][1]);
      if (r[i] >= s[i - 1] && dp[i - 1][0] != 1e18)
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
      if (r[i] >= r[i - 1] && dp[i - 1][1] != 1e18)
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
      if (dp[i][0] == 1e18 && dp[i][1] == 1e18) break;
    }
    if (i == n)
      cout << min(dp[i - 1][0], dp[i - 1][1]) << endl;
    else
      cout << -1 << endl;
  }
}
