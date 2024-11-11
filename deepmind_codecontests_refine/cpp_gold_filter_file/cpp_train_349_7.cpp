#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long double EPS = 1e-9;
int n, m;
const int N = 505;
vector<int> g[N];
bool read() {
  if (!(cin >> n >> m)) return false;
  for (int i = 0; i < int(m); ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  return false;
}
int d[N][N][2];
pair<pair<int, int>, int> from[N][N][2];
void solve() {
  for (int i = 0; i < int(N); ++i)
    for (int j = 0; j < int(N); ++j)
      for (int k = 0; k < int(2); ++k) d[i][j][k] = INF;
  d[0][n - 1][0] = 0;
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(0, n - 1), 0));
  while (!q.empty()) {
    pair<int, int> v = q.front().first;
    int cur = q.front().second;
    q.pop();
    if (cur == 0) {
      for (int i = 0; i < int(g[v.first].size()); ++i) {
        int to = g[v.first][i];
        if (d[to][v.second][1] == INF) {
          d[to][v.second][1] = d[v.first][v.second][0] + 1;
          from[to][v.second][1] = make_pair(v, cur);
          q.push(make_pair(make_pair(to, v.second), 1));
        }
      }
    } else {
      for (int i = 0; i < int(g[v.second].size()); ++i) {
        int to = g[v.second][i];
        if (to == v.first) continue;
        if (d[v.first][to][0] == INF) {
          d[v.first][to][0] = d[v.first][v.second][1] + 1;
          from[v.first][to][0] = make_pair(v, cur);
          q.push(make_pair(make_pair(v.first, to), 0));
        }
      }
    }
  }
  if (d[n - 1][0][0] == INF)
    cout << -1 << endl;
  else {
    cout << d[n - 1][0][0] / 2 << endl;
    vector<int> ans[2];
    ans[1].push_back(0);
    pair<pair<int, int>, int> cur = make_pair(make_pair(n - 1, 0), 0);
    while (cur != make_pair(make_pair(0, n - 1), 0)) {
      if (cur.second)
        ans[1].push_back(cur.first.second);
      else
        ans[0].push_back(cur.first.first);
      cur = from[cur.first.first][cur.first.second][cur.second];
    }
    ans[0].push_back(0);
    for (int i = 0; i < int(2); ++i) {
      reverse(ans[i].begin(), ans[i].end());
      for (int j = 0; j < int(ans[i].size()); ++j) cout << ans[i][j] + 1 << ' ';
      cout << endl;
    }
  }
}
int main() {
  read();
  solve();
  return 0;
}
