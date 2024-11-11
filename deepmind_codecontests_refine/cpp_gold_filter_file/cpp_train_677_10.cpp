#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> graph[3000];
int m[3000][3000];
int distFrom[3][3000];
int distTo[3][3000];
void bfs(int v) {
  queue<int> q;
  m[v][v] = 0;
  q.push(v);
  while (!q.empty()) {
    int vv = q.front();
    q.pop();
    for (int i = 0; i < (int)graph[vv].size(); ++i) {
      if (m[v][graph[vv][i]] == -1) {
        m[v][graph[vv][i]] = m[v][vv] + 1;
        q.push(graph[vv][i]);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (a != b) graph[a].push_back(b);
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      m[i][j] = -1;
    }
  for (int i = 0; i < n; ++i) {
    bfs(i);
  }
  for (int i = 0; i < n; ++i) {
    vector<pair<int, int>> dist;
    for (int j = 0; j < n; ++j) {
      if (i != j) dist.push_back(make_pair(m[i][j], j));
    }
    sort(dist.begin(), dist.end());
    reverse(dist.begin(), dist.end());
    for (int j = 0; j < 3; ++j) distFrom[j][i] = dist[j].second;
    dist.clear();
    for (int j = 0; j < n; ++j) {
      if (i != j) dist.push_back(make_pair(m[j][i], j));
    }
    sort(dist.begin(), dist.end());
    reverse(dist.begin(), dist.end());
    for (int j = 0; j < 3; ++j) distTo[j][i] = dist[j].second;
  }
  int dist = 0;
  int ans[4];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int i1 = 0; i1 < 3; ++i1)
        for (int j1 = 0; j1 < 3; ++j1)
          if (m[i][j] != -1 && m[j][distFrom[j1][j]] != -1 &&
              m[distTo[i1][i]][i] != -1 &&
              m[i][j] + m[j][distFrom[j1][j]] + m[distTo[i1][i]][i] > dist &&
              distFrom[j1][j] != distTo[i1][i] && distFrom[j1][j] != i &&
              distTo[i1][i] != j) {
            dist = m[i][j] + m[j][distFrom[j1][j]] + m[distTo[i1][i]][i];
            ans[0] = distTo[i1][i], ans[1] = i, ans[2] = j,
            ans[3] = distFrom[j1][j];
          }
    }
  for (int i = 0; i < 4; ++i) cout << ans[i] + 1 << ' ';
  return 0;
}
