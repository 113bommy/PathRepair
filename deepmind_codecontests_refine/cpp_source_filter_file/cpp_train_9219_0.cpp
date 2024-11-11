#include <bits/stdc++.h>
using namespace std;
int we[100005];
int b[100005];
bool visited[100005];
int dp[1005][1000];
vector<vector<int> > v;
int j, w, n, m;
pair<int, int> dfs(int u) {
  int a, b, k, i;
  a = we[u];
  b = ::b[u];
  for (k = 0; k <= w; k++) {
    dp[j][k] = max(dp[j][k], dp[j - 1][k]);
    if (a <= k) dp[j][k] = max(dp[j - 1][k - a] + b, dp[j][k]);
  }
  for (i = 0; i < v[u].size(); i++) {
    if (!visited[v[u][i]]) {
      visited[v[u][i]] = 1;
      pair<int, int> t = dfs(v[u][i]);
      a += t.first;
      b += t.second;
    }
  }
  return {a, b};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> w;
  int i;
  v.resize(n + 1);
  for (i = 1; i <= n; i++) {
    cin >> we[i];
  }
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 1; i <= m; i++) {
    int first, second;
    cin >> first >> second;
    v[first].push_back(second);
    v[second].push_back(first);
  }
  j = 1;
  for (i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      pair<int, int> t = dfs(i);
      int k;
      for (k = 0; k <= w; k++) {
        dp[j][k] = max(dp[j][k], dp[j - 1][k]);
        if (t.first <= k)
          dp[j][k] = max(dp[j][k], dp[j - 1][k - t.first] + t.second);
      }
      j++;
    }
  }
  cout << dp[j - 1][w];
  return 0;
}
