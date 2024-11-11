#include <bits/stdc++.h>
using namespace std;
const int mxn = 1000 * 100 + 10;
char mat[11][11][11];
int n, k, m, ans;
void dfs(int x, int y, int z) {
  if (x < 0 || y < 0 || z < 0 || x >= n || y >= m || z >= k ||
      mat[z][x][y] == '#')
    return;
  ans++;
  mat[z][x][y] = '#';
  dfs(x + 1, y, z);
  dfs(x - 1, y, z);
  dfs(x, y + 1, z);
  dfs(x, y - 1, z);
  dfs(x, y, z + 1);
  dfs(x, y, z - 1);
}
int main() {
  cin >> k >> n >> m;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++)
      for (int z = 0; z < m; z++) cin >> mat[i][j][z];
  int x, y;
  cin >> x >> y;
  dfs(--x, --y, 0);
  cout << ans;
  return 0;
}
