#include <bits/stdc++.h>
int n, m, sg[45][45][45][45][2];
char s[22][22];
int read() {
  int x = 0, f = 1;
  char s;
  while ((s = getchar()) > '9' || s < '0') {
    if (s == '-') f = -1;
    if (s == EOF) exit(0);
  }
  while (s <= '9' && s >= '0') {
    x = (x << 1) + (x << 3) + (s ^ 48);
    s = getchar();
  }
  return x * f;
}
int dfs(const int x1, const int y1, const int x2, const int y2, const int f) {
  if (x1 > x2 || y1 > y2) return 0;
  if (~sg[x1][y1][x2][y2][f]) return sg[x1][y1][x2][y2][f];
  bool vis[205] = {};
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (((i + j) & 1) == f) {
        int x = i + j, y = i - j + m;
        if (x1 > x || x2 < x || y1 > y || y2 < y) continue;
        if (s[i][j] == 'L')
          vis[dfs(x + 1, y1, x2, y2, f) ^ dfs(x1, y1, x - 1, y2, f)] = 1;
        if (s[i][j] == 'R')
          vis[dfs(x1, y + 1, x2, y2, f) ^ dfs(x1, y1, x2, y - 1, f)] = 1;
        if (s[i][j] == 'X')
          vis[dfs(x + 1, y1, x2, y - 1, f) ^ dfs(x + 1, y + 1, x2, y2, f) ^
              dfs(x1, y + 1, x - 1, y2, f) ^ dfs(x1, y1, x - 1, y - 1, f)] = 1;
      }
  for (int i = 0;; ++i)
    if (!vis[i]) return sg[x1][y1][x2][y2][f] = i;
}
int main() {
  memset(sg, -1, sizeof sg);
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  if (dfs(1, 1, n + m - 1, n + m - 1, 1) ^ dfs(1, 1, n + m - 1, n + m - 1, 0))
    puts("WIN");
  else
    puts("LOSE");
  return 0;
}
