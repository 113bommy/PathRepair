#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
char mat[N][N];
int dist[N][N][3];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    list<pair<int, int> > q;
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        if (mat[x][y] == '1' + i) {
          dist[x][y][i] = 0;
          q.emplace_back(x, y);
        } else
          dist[x][y][i] = -1;
      }
    }
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop_front();
      for (int j = 0; j < 4; j++) {
        int tx = x + dx[j], ty = y + dy[j];
        if (tx >= 0 && tx < n && ty >= 0 && ty < n && mat[tx][ty] != '#') {
          int td = dist[x][y][i] + (mat[tx][ty] == '.');
          if (dist[tx][ty][i] == -1 || dist[tx][ty][i] > td) {
            dist[tx][ty][i] = td;
            if (mat[tx][ty] == '.')
              q.emplace_back(tx, ty);
            else
              q.emplace_front(tx, ty);
          }
        }
      }
    }
  }
  int ans = 1000000000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j][0] != -1 && dist[i][j][1] != -1 && dist[i][j][2] != -1) {
        ans = min(ans, dist[i][j][0] + dist[i][j][1] + dist[i][j][2] -
                           2 * (mat[i][j] == '.'));
      }
    }
  }
  cout << (ans == 1000000000 ? -1 : ans);
}
