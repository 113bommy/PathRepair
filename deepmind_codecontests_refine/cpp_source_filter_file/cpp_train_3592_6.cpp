#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int n, m;
vector<vector<char> > graph;
vector<vector<vector<int> > > dist;
vector<vector<pair<int, int> > > ways;
void bfs(int x1, int y1, int num) {
  dist[num][x1][y1] = 0;
  deque<pair<int, int> > d;
  d.push_back({x1, y1});
  while (!d.empty()) {
    int x = d.front().first;
    int y = d.front().second;
    d.pop_front();
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (abs(i) + abs(j) == 1 && x + i >= 0 && x + i < n && y + j >= 0 &&
            y + j < m && dist[num][x + i][y + j] == INF) {
          if (graph[x + i][y + j] == '.') {
            dist[num][x + i][y + j] =
                min(dist[num][x + i][y + j], dist[num][x][y] + 1);
            d.push_back({x + i, y + j});
          } else if (graph[x + i][y + j] != '#') {
            dist[num][x + i][y + j] =
                min(dist[num][x + i][y + j], dist[num][x][y]);
            d.push_front({x + i, y + j});
          }
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  graph.resize(n, vector<char>(m));
  dist.resize(3, vector<vector<int> >(n, vector<int>(m, INF)));
  int a1, b1, a2, b2, a3, b3;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> graph[i][j];
      if (graph[i][j] == '1') {
        a1 = i;
        b1 = j;
      }
      if (graph[i][j] == '2') {
        a2 = i;
        b2 = j;
      }
      if (graph[i][j] == '3') {
        a3 = i;
        b3 = j;
      }
    }
  }
  bfs(a1, b1, 0);
  bfs(a2, b2, 1);
  bfs(a3, b3, 2);
  int ans = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (graph[i][j] == '.')
        ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
      else if (graph[i][j] != '#') {
        ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j]);
      }
    }
  }
  if (ans == 1e9) {
    cout << -1;
  } else
    cout << ans;
}
