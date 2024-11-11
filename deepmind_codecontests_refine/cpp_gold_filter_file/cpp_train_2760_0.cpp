#include <bits/stdc++.h>
using namespace std;
int n, m, vis[1010][1010], p[1000009];
int f[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char str[1010][1010];
struct node {
  int x, y;
};
bool isok(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m && str[x][y] == '.') return true;
  return false;
}
int bfs(int xi, int yi, int id) {
  int ans = 0;
  node s, e;
  s.x = xi, s.y = yi;
  queue<node> q;
  q.push(s);
  while (!q.empty()) {
    s = q.front(), q.pop();
    ans++;
    for (int i = 0; i < 4; i++) {
      e = s;
      e.x += f[i][0];
      e.y += f[i][1];
      if (isok(e.x, e.y) && !vis[e.x][e.y]) {
        vis[e.x][e.y] = id;
        q.push(e);
      }
    }
  }
  return ans;
}
int main() {
  memset(vis, 0, sizeof(vis));
  memset(p, 0, sizeof(p));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str[i] + 1);
  }
  int li = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str[i][j] == '.' && !vis[i][j]) {
        vis[i][j] = li;
        p[li] = bfs(i, j, li);
        li++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str[i][j] == '.')
        printf(".");
      else {
        int ans = p[vis[i - 1][j]];
        if (vis[i - 1][j] != vis[i + 1][j]) ans += p[vis[i + 1][j]];
        if (vis[i][j - 1] != vis[i - 1][j] && vis[i][j - 1] != vis[i + 1][j])
          ans += p[vis[i][j - 1]];
        if (vis[i][j + 1] != vis[i][j - 1] && vis[i][j + 1] != vis[i - 1][j] &&
            vis[i][j + 1] != vis[i + 1][j])
          ans += p[vis[i][j + 1]];
        printf("%d", (ans + 1) % 10);
      }
    }
    printf("\n");
  }
  return 0;
}
