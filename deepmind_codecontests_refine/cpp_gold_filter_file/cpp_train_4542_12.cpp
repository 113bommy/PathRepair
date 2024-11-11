#include <bits/stdc++.h>
using namespace std;
int dp[52][52];
int n;
vector<pair<int, int> > v[52];
bool use[52][52];
int dist[52][52];
int ans[52][52];
bool ng[52];
inline int dfs(int b, int rest, int u = 0) {
  if (rest == 0) {
    return 0;
  }
  if (use[b][rest]) return ans[b][rest];
  use[b][rest] = true;
  memset(dp[u], -1, sizeof(dp[u]));
  dp[u][0] = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (i == b) continue;
    if (v[i].size() >= 2) continue;
    for (int j = rest; j >= 0; j--) {
      if (dp[u][j] == -1) continue;
      for (int k = 1; j + k <= rest; k++) {
        int path = dist[b][i] + dfs(i, rest - k, u + 1);
        path = min(path, dp[u][j]);
        dp[u][j + k] = max(dp[u][j + k], path);
      }
    }
  }
  ans[b][rest] = dp[u][rest];
  return ans[b][rest];
}
int flag[52];
vector<int> child;
inline int dfs2(int b, int pr) {
  ng[b] = false;
  int r = flag[b];
  int nex = 0;
  for (auto go : v[b]) {
    if (go.first == pr) continue;
    r += dfs2(go.first, b);
    nex++;
  }
  if (nex <= 0) {
    child.push_back(b);
  }
  return r;
}
int D[52];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = INT_MAX;
      if (i == j) dist[i][j] = 0;
    }
  }
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
    dist[a][b] = c;
    dist[b][a] = c;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (dist[j][i] != INT_MAX && dist[k][i] != INT_MAX) {
          dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
          dist[k][j] = min(dist[k][j], dist[j][k]);
        }
      }
    }
  }
  int root;
  scanf("%d", &root);
  root--;
  int ans = INT_MAX;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    x--;
    flag[x]++;
  }
  for (auto go : v[root]) {
    fill(ng, ng + 52, true);
    child.clear();
    int rest = dfs2(go.first, root);
    if (rest == 0) continue;
    memset(use, false, sizeof(use));
    memset(D, -1, sizeof(D));
    D[0] = INT_MAX;
    for (int k : child) {
      for (int i = rest; i >= 0; i--) {
        if (D[i] == -1) continue;
        for (int j = 1; i + j <= rest; j++) {
          int cost = dist[go.first][k] + dfs(k, m - j, 0);
          cost = min(cost, D[i]);
          D[i + j] = max(D[i + j], cost);
        }
      }
    }
    ans = min(ans, D[rest] + go.second);
  }
  cout << ans << endl;
  return 0;
}
