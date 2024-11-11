#include <bits/stdc++.h>
using namespace std;
bool cannot_go[101][101][4], was[101][101];
int local, cnt(-1), n, ans[111], w, h;
void dfs(int i, int j) {
  ++local;
  was[i][j] = true;
  if (i > 1 && !cannot_go[i][j][2] && !was[i - 1][j]) dfs(i - 1, j);
  if (i < w && !cannot_go[i][j][3] && !was[i + 1][j]) dfs(i + 1, j);
  if (j > 1 && !cannot_go[i][j][1] && !was[i][j - 1]) dfs(i, j - 1);
  if (j < h && !cannot_go[i][j][0] && !was[i][j + 1]) dfs(i, j + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> w >> h >> n;
  int x1, x2, y1, y2;
  for (; n; --n) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
      for (int y(y1 + 1); y <= y2; ++y)
        cannot_go[x1][y][3] = cannot_go[x1 + 1][y][2] = true;
    else
      for (int x(x1 + 1); x <= x2; ++x)
        cannot_go[x][y1][0] = cannot_go[x][y1 + 1][1] = true;
  }
  for (int x(1); x <= w; ++x)
    for (int y(1); y <= h; ++y)
      if (!was[x][y]) {
        local = 0;
        dfs(x, y);
        ans[++cnt] = local;
      }
  sort(ans, ans + cnt + 1);
  for (int i(0); i <= cnt; ++i) cout << ans[i] << ' ';
}
