#include <bits/stdc++.h>
using namespace std;
const long long MX = 303030;
const long long INF = 9e15;
int n, m, a[1111][1111], vis[1111][1111], dx[4] = {0, 1, 0, -1},
                                          dy[4] = {1, 0, -1, 0}, t;
struct info {
  long long x, y, cnt;
};
queue<info> qu;
bool check(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[x][y] == a[nx][ny]) {
      return 1;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char x;
      cin >> x;
      a[i][j] = x - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (check(i, j)) {
        vis[i][j] = 2;
        qu.push({i, j, 0});
      }
    }
  }
  for (int ti = 0; ti <= max(n, m); ti++) {
    while (!qu.empty()) {
      long long x = qu.front().x;
      long long y = qu.front().y;
      long long cnt = qu.front().cnt;
      if (cnt == ti + 1) break;
      qu.pop();
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] &&
            a[x][y] == 1 - a[nx][ny]) {
          vis[nx][ny] = vis[x][y] + 1;
          qu.push({nx, ny, ti + 1});
        }
      }
    }
  }
  while (t--) {
    long long x, y, p;
    cin >> x >> y >> p;
    if (vis[x][y] && p >= vis[x][y] - 1)
      cout << (a[x][y] % 2 + vis[x][y] + p) % 2 << "\n";
    else
      cout << a[x][y] << "\n";
  }
}
