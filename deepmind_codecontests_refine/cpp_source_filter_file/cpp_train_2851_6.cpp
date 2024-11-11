#include <bits/stdc++.h>
using namespace std;
long long int mad = 1e9 + 7;
vector<vector<long long int>> matrix, graph, result;
vector<long long int> visited, stck;
vector<long long int> topresult;
vector<long long> fact;
bool cycle = false;
long long int dx[] = {1, -1, 0, 0};
long long int dy[] = {0, 0, 1, -1};
long long int binarysearch(vector<long long int>& kan, long long int value) {
  long long int r = kan.size() - 1, l = 0;
  long long int ans = -1;
  while (l <= r) {
    long long int mid = (l + r) >> 1;
    if (kan[mid] <= value) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}
long long int turn;
void dfs(long long int node) {
  if (turn) {
    visited[node] = 1;
    turn = 0;
  } else {
    visited[node] = 2;
    turn = 1;
  }
  for (auto it : graph[node]) {
    if (visited[it] == 0) dfs(it);
  }
}
const double PI = 3.14159265;
const double IS = 180.000;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int t, w;
  vector<vector<long long int>> dp(3);
  for (long long int i = 0; i < n; i++) {
    cin >> t >> w;
    if (t == 1)
      dp[1].push_back(w);
    else
      dp[2].push_back(w);
  }
  long long int ans = INT_MAX;
  sort(dp[1].begin(), dp[1].end());
  sort(dp[2].begin(), dp[2].end());
  for (long long int h = 0; h < dp[1].size(); h++) {
    for (long long int w = 0; w < dp[2].size(); w++) {
      long long int s = 0;
      for (long long int i = 0; i < dp[1].size() - h; i++) s += dp[1][0];
      for (long long int j = 0; j < dp[2].size() - w; j++) s += dp[2][0];
      if (h + 2 * w >= s && ans > h + 2 * w) ans = h + 2 * w;
    }
  }
  cout << ans << "\n";
}
