#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int INF = 100000;
vector<string> a;
int n, m;
bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
vector<vector<int> > bfs(char st) {
  queue<pair<int, int> > q;
  vector<vector<int> > d(n, vector<int>(m, INF));
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      if (a[i][j] == st) {
        d[i][j] = 0;
        q.push(make_pair(i, j));
      }
    }
  }
  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    for (int i = 0; i < (int)(4); i++) {
      pair<int, int> v = make_pair(u.first + dx[i], u.second + dy[i]);
      if (!valid(v.first, v.second) || d[v.first][v.second] != INF ||
          a[v.first][v.second] == '#')
        continue;
      q.push(v);
      d[v.first][v.second] = d[u.first][u.second] + 1;
    }
  }
  return d;
}
int main() {
  cin >> n >> m;
  a = vector<string>(n);
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  vector<vector<int> > d1 = bfs('1');
  vector<vector<int> > d2 = bfs('2');
  vector<vector<int> > d3 = bfs('3');
  int d12 = INF, d13 = INF, d23 = INF;
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      if (a[i][j] == '1') {
        d12 = min(d12, d2[i][j]);
        d13 = min(d13, d3[i][j]);
      }
      if (a[i][j] == '2') {
        d23 = min(d23, d3[i][j]);
      }
    }
  }
  int ans = min(d12 - 1 + d23 - 1, min(d13 - 1 + d23 - 1, d12 - 1 + d13 - 1));
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      if (a[i][j] == '.') {
        ans = min(ans, d1[i][j] + d2[i][j] + d3[i][j] - 2);
      }
    }
  }
  if (ans >= INF / 2) ans = -1;
  cout << ans << endl;
  return 0;
}
