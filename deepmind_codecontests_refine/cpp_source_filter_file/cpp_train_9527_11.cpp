#include <bits/stdc++.h>
using namespace std;
int k, n, m;
char plate[10][10][10];
int vis[10][10][10];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int tt = 0;
bool valid(int x, int y, int z) {
  return z >= 0 && x >= 0 && y >= 0 && z < k && x < n && y < m &&
         plate[x][y][z] == '.';
}
void dfs(int x, int y, int z) {
  if (vis[x][y][z]) return;
  vis[x][y][z] = ++tt;
  for (int i = 0; i < 6; i++) {
    if (valid(x + dx[i], y + dy[i], z + dz[i]))
      dfs(x + dx[i], y + dy[i], z + dz[i]);
  }
}
int main() {
  cin >> k >> n >> m;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      for (int p = 0; p < m; p++) cin >> plate[i][j][p];
    }
  }
  int x, y;
  cin >> x >> y;
  --x;
  --y;
  dfs(x, y, 0);
  cout << tt << endl;
}
