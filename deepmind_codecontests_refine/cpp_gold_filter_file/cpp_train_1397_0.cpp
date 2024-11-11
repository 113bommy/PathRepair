#include <bits/stdc++.h>
using namespace std;
bool s(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > v(n + 1, make_pair(0, 0));
  for (int i = 1; i <= n; i++) cin >> v[i].first;
  for (int i = 1; i <= n; i++) cin >> v[i].second;
  sort(v.begin() + 1, v.end(), s);
  int dp[n + 2][200002];
  int shift = 10000;
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) {
    int foo = v[i].first - k * v[i].second + shift;
    int fop = v[i + 1].first - k * v[i + 1].second;
    dp[i][foo] = max(v[i].first, dp[i][foo]);
    for (int j = 1; j <= 200002; j++) {
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
      if (j + fop > 0 && j + fop <= 200002 && dp[i][j] != 0) {
        dp[i + 1][j + fop] = max(dp[i][j] + v[i + 1].first, dp[i + 1][j + fop]);
      }
    }
  }
  if (dp[n][10000] == 0)
    cout << -1;
  else
    cout << dp[n][10000];
}
