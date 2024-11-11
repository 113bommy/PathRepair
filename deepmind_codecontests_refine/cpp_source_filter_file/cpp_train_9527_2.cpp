#include <bits/stdc++.h>
using namespace std;
char ch[15][15][15];
bool visited[15][15][15];
void dfs(int k, int n, int m, int z, int x, int y) {
  visited[z][x][y] = true;
  if (z + 1 < k && (!visited[z + 1][x][y]) && ch[z + 1][x][y] == '.') {
    dfs(k, n, m, z + 1, x, y);
  }
  if (z - 1 >= 0 && (!visited[z - 1][x][y]) && ch[z - 1][x][y] == '.') {
    dfs(k, n, m, z - 1, x, y);
  }
  if (x + 1 < n && (!visited[z][x + 1][y]) && ch[z][x + 1][y] == '.') {
    dfs(k, n, m, z, x + 1, y);
  }
  if (x - 1 >= 0 && (!visited[z][x - 1][y]) && ch[z][x - 1][y] == '.') {
    dfs(k, n, m, z, x - 1, y);
  }
  if (y + 1 < m && (!visited[z][x][y + 1]) && ch[z][x][y + 1] == '.') {
    dfs(k, n, m, z, x, y + 1);
  }
  if (y - 1 >= 0 && (!visited[z][x][y - 1]) && ch[z][x][y - 1] == '.') {
    dfs(k, n, m, z + 1, x, y - 1);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int k, n, m, x, y, c = 0;
  cin >> k >> n >> m;
  for (int l = 0; l < k; l++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> ch[l][i][j];
      }
    }
  }
  cin >> x >> y;
  memset(visited, false, sizeof visited);
  x--;
  y--;
  dfs(k, n, m, 0, x, y);
  for (int l = 0; l < k; l++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[l][i][j]) {
          c++;
        }
      }
    }
  }
  cout << c;
  return 0;
}
