#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vert(2e5 + 1, vector<int>(0));
vector<bool> was(2e5 + 1, false);
vector<pair<int, int>> diap(0);
vector<pair<int, int>> arr(0);
int dp[81][(int)1e5 + 1];
long long child, edge;
void dfs(int v) {
  was[v] = true;
  for (int son : vert[v]) {
    if (was[son])
      continue;
    else {
      dfs(son);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr.begin(), arr.end());
  for (int i = 1; i <= m; i++) {
    dp[0][i] = max(max(arr[0].first - arr[0].second - 1, 0),
                   max(i - (arr[0].first + arr[0].second), 0));
  }
  int left = -arr[0].second + arr[0].first;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= min(arr[i].first + arr[i].second, m); j++) {
      if (arr[i].first - arr[i].second <= left) {
        dp[i][j] = max(arr[i].first - arr[i].second - 1, 0);
      } else {
        dp[i][j] = dp[i - 1][min(j, max(arr[i].first - arr[i].second - 1, 0))];
      }
    }
    for (int j = min(arr[i].first + arr[i].second, m) + 1; j <= m; j++) {
      int distr = j - (arr[i].first + arr[i].second);
      dp[i][j] =
          min(dp[i - 1][j],
              ((arr[i].first - arr[i].second - distr >= 1)
                   ? (dp[i - 1][arr[i].first - arr[i].second - distr - 1])
                   : 0) +
                  distr);
      dp[i][j] = min(dp[i][j], max(max(j - (arr[i].first + arr[i].second), 0),
                                   max(0, (arr[i].first - arr[i].second) - 1)));
    }
    left = min(-arr[i].second + arr[i].first, left);
  }
  cout << dp[n - 1][m];
  return 0;
}
