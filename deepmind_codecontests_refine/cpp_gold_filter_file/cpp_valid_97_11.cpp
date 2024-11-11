#include <bits/stdc++.h>
using namespace std;
const int M = 505;
const int N = M * M;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, m, ans[N];
char s[M][M];
vector<int> g[N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int id(int x, int y) { return (x - 1) * m + y; }
void add(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
void dfs(int u, int ls) {
  ans[u] = ls;
  for (auto v : g[u])
    if (!ans[v]) dfs(v, 5 - ls);
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == 'X') {
        int d = 0, a[4] = {};
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (x < 1 || y < 1 || x > n || y > m) continue;
          if (s[x][y] == '.') a[d++] = id(x, y);
        }
        if (d & 1) {
          puts("NO");
          return 0;
        }
        for (int i = 0; i < d; i++) add(a[i], a[(i + 1) % d]);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.' && !ans[id(i, j)]) dfs(id(i, j), 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == 'X')
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (x < 1 || y < 1 || x > n || y > m) continue;
          if (s[x][y] == '.') ans[id(i, j)] += ans[id(x, y)];
        }
  puts("YES");
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= m; j++) printf("%d ", ans[id(i, j)]);
}
