#include <bits/stdc++.h>
using namespace std;
int d[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int ans, k = 0;
int egg[1000000];
int n, m, vis[1050][1050]{0}, ma[1050][1050];
void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int xx = x + d[i][0];
    int yy = y + d[i][1];
    if ((ma[x][y] >> i) % 2 == 0 && vis[xx][yy] == 0) {
      vis[xx][yy] = 1;
      dfs(xx, yy);
      ans++;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ma[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        ans = 1;
        vis[i][j] = 1;
        dfs(i, j);
        egg[++k] = ans;
      }
    }
  }
  sort(egg + 1, egg + k + 1);
  for (int i = k; i >= 1; i--) {
    cout << egg[i] << " ";
  }
  return 0;
}
