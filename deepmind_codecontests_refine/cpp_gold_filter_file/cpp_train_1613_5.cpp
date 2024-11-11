#include <bits/stdc++.h>
using namespace std;
int dist[3030][3030];
vector<int> p[3030];
void bfs(int x) {
  bool v[3030];
  memset(v, 0, sizeof(v));
  queue<pair<int, int> > q;
  v[x] = 1;
  q.push(make_pair(0, x));
  pair<int, int> t;
  while (!q.empty()) {
    t = q.front();
    q.pop();
    for (int i = 0; i < p[t.second].size(); i++) {
      if (!v[p[t.second][i]]) {
        v[p[t.second][i]] = 1;
        dist[p[t.second][i]][x] = t.first + 1;
        dist[x][p[t.second][i]] = t.first + 1;
        q.push(make_pair(t.first + 1, p[t.second][i]));
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    dist[x][y] = 1;
    dist[y][x] = 1;
    p[x].push_back(y);
    p[y].push_back(x);
  }
  int x1, y1, c1;
  int x2, y2, c2;
  cin >> x1 >> y1 >> c1;
  cin >> x2 >> y2 >> c2;
  for (int i = 1; i <= n; i++) {
    bfs(i);
  }
  if (dist[x1][y1] > c1 || dist[x2][y2] > c2) {
    cout << -1;
    return 0;
  }
  int maxx = m - dist[x1][y1] - dist[x2][y2];
  int com, r1, r2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      r1 = min(dist[x1][i] + dist[y1][j], dist[x1][j] + dist[y1][i]);
      r2 = min(dist[x2][i] + dist[y2][j], dist[x2][i] + dist[y2][i]);
      com = dist[i][j];
      if (com + r1 > c1 || com + r2 > c2) continue;
      maxx = max(maxx, m - r1 - r2 - com);
    }
  }
  cout << maxx;
  return 0;
}
