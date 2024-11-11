#include <bits/stdc++.h>
using namespace std;
int weight;
int beauty;
int w[1005];
int b[1003];
int dp[2002][1003];
vector<pair<int, int>> v;
void dfs(int x, vector<int> adj[], bool visited[]) {
  visited[x] = true;
  for (auto& i : adj[x]) {
    if (visited[i] == false) {
      dfs(i, adj, visited);
    }
  }
  v.push_back(make_pair(w[x], b[x]));
  weight += w[x];
  beauty += b[x];
}
void solve() {
  int n, m, mxw;
  cin >> n >> m >> mxw;
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<int> adj[n];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  bool visited[n];
  for (int i = 0; i < n; i++) visited[i] = false;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      weight = 0;
      beauty = 0;
      dfs(i, adj, visited);
      v.push_back({weight, beauty});
      cnt++;
      for (int j = mxw; j >= 0; j--) {
        for (int k = 0; k < v.size(); k++) {
          if (j >= v[k].first) {
            dp[cnt][j] =
                max(dp[cnt][j], dp[cnt - 1][j - v[k].first] + v[k].second);
            dp[cnt][j] = max(dp[cnt][j], dp[cnt - 1][j]);
          } else
            dp[cnt][j] = max(dp[cnt][j], dp[cnt - 1][j]);
        }
      }
      v.clear();
    }
  }
  int ans = 0;
  for (int i = 1; i <= cnt; i++) {
    for (int j = 0; j <= mxw; j++) ans = max(ans, dp[i][j]);
  }
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
