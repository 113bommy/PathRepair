#include <bits/stdc++.h>
using namespace std;
int dp[30][30];
int main() {
  int n;
  cin >> n;
  memset(dp, 0, sizeof dp);
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    int a = v[i][0] - 'a';
    int b = v[i][v[i].size() - 1] - 'a';
    int len = v[i].size();
    for (int j = 0; j < 25; j++) {
      if (dp[j][a] != 0) {
        dp[j][b] = max(dp[j][b], (int)(dp[j][a] + v[i].size()));
      }
    }
    dp[a][b] = max(dp[a][b], len);
  }
  int ans = 0;
  for (int i = 0; i < 25; i++) ans = max(ans, dp[i][i]);
  cout << ans << "\n";
  return 0;
}
