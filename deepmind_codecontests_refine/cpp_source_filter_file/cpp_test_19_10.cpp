#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int M = 1501, inf = 100000000;
    vector<vector<int> > dp(n + 1, vector<int>(M, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < M; j++) {
        if (dp[i][j] == inf) continue;
        int newjleft = max(0, j - a[i]);
        int incleft = max(0, a[i] - j);
        dp[i + 1][newjleft] = min(dp[i + 1][newjleft], dp[i][j] + incleft);
        if (a[i] + j >= M) continue;
        int distFromRight = dp[i][j] - j;
        int newjright = j + a[i];
        int incRight = max(0, a[i] - distFromRight);
        dp[i + 1][newjright] = min(dp[i + 1][newjright], dp[i][j] + incRight);
      }
    }
    int ans = INT_MAX;
    for (int pos = 0; pos < M; pos++) ans = min(ans, dp[n][pos]);
    cout << ans << endl;
  }
}
