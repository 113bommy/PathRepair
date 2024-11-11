#include <bits/stdc++.h>
using namespace std;
const int N = 3000 + 100;
int p[N];
int d[N][N];
pair<int, int> dp[4][N];
int ans[100][5];
vector<int> g[N];
int n, m;
queue<int> q;
void bfs(int x) {
  d[x][x] = 0;
  q.push(x);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : g[v]) {
      if (d[x][u] == -1) {
        d[x][u] = d[x][v] + 1;
        q.push(u);
      }
    }
  }
}
void doJob(int x) {
  for (int i = 0; i < n; ++i) dp[0][i] = {0, p[i]};
  for (int k = 1; k < 4; ++k) {
    for (int i = 0; i < n; ++i) {
      int mx = -1, id = 0;
      for (int j = 0; j < i; ++j) {
        if (d[p[i]][p[j]] != -1 && dp[k - 1][j].first != -1 &&
            mx < d[p[i]][p[j]] + dp[k - 1][j].first) {
          mx = d[p[i]][p[j]] + dp[k - 1][j].first;
          id = j;
        }
      }
      dp[k][i] = {mx, id};
    }
  }
  int mx = -1, id = 0;
  for (int i = 0; i < n; ++i) {
    if (mx < dp[3][i].first) {
      mx = dp[3][i].first;
      id = i;
    }
  }
  ans[x][0] = mx;
  ans[x][1] = p[id] + 1;
  id = dp[3][id].second;
  ans[x][2] = p[id] + 1;
  id = dp[2][id].second;
  ans[x][3] = p[id] + 1;
  id = dp[1][id].second;
  ans[x][4] = p[id] + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(d, -1, sizeof d);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
  }
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < n; ++i) bfs(i);
  for (int i = 0; i < 50; ++i) {
    random_shuffle(p, p + n);
    doJob(i);
  }
  int mx = -1, id = 0;
  for (int i = 0; i < 50; ++i) {
    if (mx < ans[i][0]) {
      mx = ans[i][0];
      id = i;
    }
  }
  cout << ans[id][1] << " " << ans[id][2] << " " << ans[id][3] << " "
       << ans[id][4] << "\n";
  return 0;
}
