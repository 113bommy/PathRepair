#include <bits/stdc++.h>
using namespace std;
int color[1005][1005];
int dir[8][2] = {{-1, 2},  {-1, -2}, {1, 2},  {1, -2},
                 {-2, -1}, {-2, 1},  {2, -1}, {2, 1}};
int cnt[2], n, m;
void dfs(int y, int x, int c) {
  if (y < 1 || x < 1 || y > n || x > m) return;
  if (color[y][x] != -1) return;
  color[y][x] = c;
  cnt[c]++;
  for (int i = 0; i < 8; i++) {
    int ny = y + dir[i][0];
    int nx = x + dir[i][1];
    dfs(ny, nx, 1 - c);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> m;
  memset(color, -1, sizeof(color));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (color[i][j] != -1) continue;
      cnt[0] = cnt[1] = 0;
      dfs(i, j, 0);
      ans += max(cnt[0], cnt[1]);
    }
  }
  cout << ans << endl;
}
