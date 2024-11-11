#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11;
int k, n, m, sx, sy;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
bool vis[MAXN][MAXN][MAXN];
string temp, s[MAXN][MAXN];
bool inside(int x, int y, int z) {
  return 0 <= x and x < n and 0 <= y and y < m and 0 <= z and z < k;
}
int dfs(int x, int y, int z) {
  if (not inside(x, y, z)) return 0;
  if (vis[x][y][z]) return 0;
  if (s[z][x][y] == '#') return 0;
  vis[x][y][z] = true;
  int ans = 1;
  for (int i = 0; i < 6; i++) {
    int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
    ans += dfs(nx, ny, nz);
  }
  return ans;
}
int main() {
  cin >> k >> n >> m;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) cin >> s[i][j];
  }
  cin >> sx >> sy;
  sx--, sy--;
  cout << dfs(0, sx, sy) << endl;
  return 0;
}
