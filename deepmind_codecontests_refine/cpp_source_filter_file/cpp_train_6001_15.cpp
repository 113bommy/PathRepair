#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int g[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int sx, sy, tx, ty, n, m, ans, len, p[4];
bool vis[4];
char St[N][N];
char s[N];
void dfs(int x) {
  if (x > 3) {
    int x = sx, y = sy;
    for (int i = 1; i <= len; i++) {
      int now = s[i] - '0';
      x += g[p[now]][0];
      y += g[p[now]][1];
      if (x < 0 || x > n || y < 0 || y > m) return;
      if (St[x][y] == '#') return;
      if (St[x][y] == 'E') {
        ans++;
        return;
      }
    }
    return;
  }
  for (int i = 0; i <= 3; i++)
    if (!vis[i]) {
      vis[i] = 1;
      p[x] = i;
      dfs(x + 1);
      vis[i] = 0;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", St[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (St[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (St[i][j] == 'E') {
        tx = i;
        ty = j;
      }
    }
  }
  scanf("%s", s + 1);
  len = strlen(s + 1);
  dfs(0);
  printf("%d\n", ans);
}
