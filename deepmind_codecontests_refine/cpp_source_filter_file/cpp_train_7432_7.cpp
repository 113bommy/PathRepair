#include <bits/stdc++.h>
using namespace std;
bool edge[101][101][4];
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
int h, w, n, cnt;
bool used[101][101];
bool in(int x, int y) { return (x >= 0 && x < w && y >= 0 && y < h); }
void dfs(int x, int y) {
  if (!in(x, y)) return;
  used[x][y] = true;
  cnt++;
  for (int i = 0; i < 4; i++)
    if (!edge[x][y][i] && in(x + dx[i], y + dy[i]) &&
        !used[x + dx[i]][y + dy[i]])
      dfs(x + dx[i], y + dy[i]);
}
int main() {
  int x1, y1, x2, y2, i, j;
  cin >> h >> w >> n;
  memset(used, 0, sizeof(used));
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
      for (j = y1; j < y2; j++) edge[x1 - 1][j][0] = edge[x1][j][1] = true;
    else
      for (j = x1; j < x2; j++) edge[j][y1 - 1][2] = edge[j][y1][3] = true;
  }
  vector<int> ans;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (!used[j][i]) {
        cnt = 0;
        dfs(j, i);
        ans.push_back(cnt);
      }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
