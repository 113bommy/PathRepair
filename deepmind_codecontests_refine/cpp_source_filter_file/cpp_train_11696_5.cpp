#include <bits/stdc++.h>
char con[1500][1502];
int n, m, dir[4][2], vis[1500][1500][2];
bool dfs(int r, int c) {
  if (con[r % n][c % m] == '#') return false;
  if (vis[r % n][c % m][0] != -1) {
    if (vis[r % n][c % m][0] != r || vis[r % n][c % m][1] != c)
      return true;
    else
      return false;
  }
  vis[r % n][c % m][0] = r, vis[r % n][c % m][1] = c;
  bool suc = false;
  for (int i = 0; i < 4; i++)
    if (dfs((r + dir[i][0]), (c + dir[i][1]))) suc = true;
  return suc;
}
int main() {
  int r, c;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", con[i]);
  for (int i = 0; i < 1500; i++)
    for (int j = 0; j < 1500; j++) vis[i][j][0] = vis[i][j][1] = -1;
  dir[0][0] = 0, dir[0][1] = 1;
  dir[1][0] = 1, dir[1][1] = 0;
  dir[2][0] = 0, dir[2][1] = -1;
  dir[3][0] = -1, dir[3][1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (con[i][j] == 'S') r = i, c = j;
    }
  }
  if (dfs(r + 10 * n, c + 10 * m))
    puts("YES");
  else
    puts("NO");
}
