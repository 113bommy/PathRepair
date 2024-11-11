#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char arr[N][N] = {};
bool vis[N][N] = {};
int n, m;
inline bool valid(int nx, int ny) {
  return (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] &&
          arr[nx][ny] == '#');
}
void dfs(int xx, int yy) {
  vis[xx][yy] = true;
  for (int i = -1; i <= (int)1; ++i) {
    for (int j = -1; j <= (int)1; ++j) {
      if (j != i && (!j || !i)) {
        int nx = xx + i;
        int ny = yy + j;
        if (valid(nx, ny)) dfs(nx, ny);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 1; i <= (int)n; ++i)
    for (int j = 1; j <= (int)m; ++j) cin >> arr[i][j];
  int z = 0;
  for (int x = 1; x <= (int)n; ++x) {
    for (int y = 1; y <= (int)m; ++y) {
      if (arr[x][y] == '#') {
        z++;
        arr[x][y] = '.';
        int cmp = 0;
        memset(vis, 0, sizeof(vis));
        ;
        for (int i = 1; i <= (int)n; ++i) {
          for (int j = 1; j <= (int)m; ++j) {
            if (!vis[i][j] && arr[i][j] == '#') {
              dfs(i, j);
              ++cmp;
            }
          }
        }
        if (cmp >= 2) return cout << 1 << "\n", 0;
        arr[x][y] = '#';
      }
    }
  }
  if (z <= 2) return cout << -1 << "\n", 0;
  return cout << 2 << "\n", 0;
  return 0;
}
