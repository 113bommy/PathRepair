#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int n;
int sx, sy, ex, ey, qx, qy;
bool block[1005][1005];
bool vis[1005][1005];
void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    if (x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= n &&
        !(vis[x + dx[i]][y + dy[i]] == 1) && block[x + dx[i]][y + dy[i]] != 1) {
      dfs(x + dx[i], y + dy[i]);
    }
  }
}
int main() {
  cin >> n >> qx >> qy >> sx >> sy >> ex >> ey;
  for (int i = 1; i <= n; i++) {
    block[qx][i] = 1;
    block[i][qy] = 1;
  }
  dfs(sx, sy);
  if (vis[ex][ey] == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
