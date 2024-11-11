#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int n, m, k, f[510][510];
string s[510];
struct _res {
  char c;
  int x;
  int y;
} res[1000010];
void dfs(int cx, int cy, int px, int py) {
  f[cx][cy] = 1;
  for (int ii = 0; ii < 4; ii++) {
    int nx = cx + dx[ii];
    int ny = cy + dy[ii];
    if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
    if (!f[nx][ny] && s[nx][ny] != '#') dfs(nx, ny, cx, cy);
  }
  if (px != -1 && py != -1) {
    res[k++] = (struct _res){'B', px, py};
    res[k++] = (struct _res){'R', cx, cy};
    res[k++] = (struct _res){'D', px, py};
  } else
    res[k++] = (struct _res){'B', cx, cy};
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!f[i][j] && s[i][j] != '#') dfs(i, j, -1, -1);
  cout << k << endl;
  for (int i = 0; i < k; i++)
    cout << res[i].c << " " << res[i].x << " " << res[i].y << endl;
}
