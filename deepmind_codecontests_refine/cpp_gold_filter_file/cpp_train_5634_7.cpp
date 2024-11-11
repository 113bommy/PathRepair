#include <bits/stdc++.h>
using namespace std;
char s[1005][1005];
int vis[1005][1005];
void bfs(int x, int y) {
  for (int i = 0; i < 3; i++) {
    if (s[x + i][y] == '.') {
      return;
    }
    if (s[x + i][y + 2] == '.') {
      return;
    }
  }
  if (s[x][y + 1] == '.' || s[x + 2][y + 1] == '.') {
    return;
  }
  for (int i = 0; i < 3; i++) {
    vis[x + i][y] = 1;
    vis[x + i][y + 2] = 1;
  }
  vis[x][y + 1] = 1;
  vis[x + 2][y + 1] = 1;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      bfs(i, j);
    }
  }
  bool f = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((s[i][j] == '#' && vis[i][j] == 0) ||
          (s[i][j] == '.' && vis[i][j] == 1)) {
        f = false;
      }
    }
    if (!f) break;
  }
  if (f)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
