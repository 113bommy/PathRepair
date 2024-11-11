#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
const int N = 405;
int dist[N];
int mat[N][2];
int dijkstra(int flg, int n) {
  memset(dist, -1, sizeof(dist));
  queue<int> q;
  dist[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = (1); v < (n + 1); v++) {
      if (mat[u][v] != flg && dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist[n];
}
int main() {
  int n, m, x, y;
  cin >> n >> m;
  for (int i = (0); i < (m); i++) {
    scanf("%d%d", &x, &y);
    mat[x][y] = mat[y][x] = 1;
  }
  int flg = mat[1][n];
  int res = dijkstra(flg, n);
  cout << res;
}
