#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct point {
  int x, y, c;
  bool operator<(const point &hs) const { return (c < hs.c); }
};
int d_x[] = {0, 0, -1, 1};
int d_y[] = {1, -1, 0, 0};
vector<point> res;
int cnt;
void DFS(int x, int y, vector<vector<char>> &graph) {
  graph[x][y] = '*';
  cnt++;
  for (int i = 0; i < 4; i++) {
    int nxtx = x + d_x[i];
    int nxty = y + d_y[i];
    if (nxtx >= 0 && nxtx <= n - 1 && nxty >= 0 && nxty <= m - 1 &&
        graph[nxtx][nxty] == '.')
      DFS(nxtx, nxty, graph);
  }
}
int main() {
  cin >> n >> m >> k;
  vector<vector<char>> graph(n, vector<char>(m));
  vector<point> res;
  char symbol;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> symbol;
      graph[i][j] = symbol;
    }
  }
  vector<vector<char>> temp(graph);
  for (int j = 0; j < m; j++) {
    if (graph[0][j] == '.') {
      DFS(1, j, graph);
    }
    if (graph[n - 1][j] == '.') {
      DFS(n - 1, j, graph);
    }
  }
  for (int i = 0; i < n; i++) {
    if (graph[i][0] == '.') {
      DFS(i, 0, graph);
    }
    if (graph[i][m - 1] == '.') {
      DFS(i, m - 1, graph);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (graph[i][j] == '.') {
        cnt = 0;
        DFS(i, j, graph);
        res.push_back(point{i, j, cnt});
      }
    }
  }
  int sum = 0;
  int d = res.size();
  d -= k;
  sort(res.begin(), res.end());
  for (int i = 0; i < d; i++) {
    sum += res[i].c;
    DFS(res[i].x, res[i].y, temp);
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << temp[i][j];
    }
    cout << endl;
  }
  return 0;
}
