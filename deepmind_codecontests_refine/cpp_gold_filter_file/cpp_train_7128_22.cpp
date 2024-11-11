#include <bits/stdc++.h>
struct node {
  int x, y;
} q[4000010];
int n, m, front, rear, ans, vis[2005][2005];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char map[2005][2005];
void Judge(int x, int y) {
  int i, a, b, cnt;
  for (i = 0, cnt = 0; i < 4; i++) {
    a = x + dx[i];
    b = y + dy[i];
    if (a >= 0 && a < n && b >= 0 && b < m && map[a][b] == '.') cnt++;
  }
  if (cnt == 0)
    ans = 0;
  else if (cnt == 1 && vis[x][y] == 0)
    vis[x][y] = 1, q[rear].x = x, q[rear++].y = y;
}
int Topo() {
  int i, j, a, b, x, y, cnt;
  while (front < rear) {
    if (ans == 0) return 0;
    x = q[front].x;
    y = q[front++].y;
    if (map[x][y] != '.') continue;
    if (y + 1 < m && map[x][y + 1] == '.') {
      map[x][y] = '<', map[x][y + 1] = '>';
      for (i = 0; i < 4; i++) {
        a = x + dx[i];
        b = y + 1 + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b] == '.') Judge(a, b);
      }
    } else if (x + 1 < n && map[x + 1][y] == '.') {
      map[x][y] = '^', map[x + 1][y] = 'v';
      for (i = 0; i < 4; i++) {
        a = x + 1 + dx[i];
        b = y + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b] == '.') Judge(a, b);
      }
    } else if (y - 1 >= 0 && map[x][y - 1] == '.') {
      map[x][y] = '>', map[x][y - 1] = '<';
      for (i = 0; i < 4; i++) {
        a = x + dx[i];
        b = y - 1 + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b] == '.') Judge(a, b);
      }
    } else if (x - 1 >= 0 && map[x - 1][y] == '.') {
      map[x][y] = 'v', map[x - 1][y] = '^';
      for (i = 0; i < 4; i++) {
        a = x - 1 + dx[i];
        b = y + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && map[a][b] == '.') Judge(a, b);
      }
    }
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (map[i][j] == '.') return 0;
  return 1;
}
int main() {
  int i, j, a, b, cnt;
  while (scanf("%d%d", &n, &m) != EOF) {
    front = rear = 0;
    ans = 1;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < n; i++) scanf("%s", map[i]);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        if (map[i][j] == '.') Judge(i, j);
    if (Topo() == 0)
      printf("Not unique\n");
    else {
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) printf("%c", map[i][j]);
        printf("\n");
      }
    }
  }
  return 0;
}
