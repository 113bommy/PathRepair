#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int id[N][N], fa[N * N], n, m, t, cnt, st[N * N];
char s[N][N];
bool g[N * N];
vector<int> e[N * N];
int fset(int u) {
  if (fa[u] == u) return fa[u];
  return fa[u] = fset(fa[u]);
}
void uset(int u, int v) {
  u = fset(u), v = fset(v);
  if (u != v) fa[u] = v, g[v] |= g[u];
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) id[i][j] = ++cnt, fa[cnt] = cnt;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      for (int k = 0; k < 4; ++k) {
        int x = dx[k] + i, y = dy[k] + j;
        if (!x || !y || x > n || y > m) continue;
        if (s[x][y] == s[i][j]) {
          g[id[i][j]] = true;
          uset(id[i][j], id[x][y]);
        }
      }
    }
  memset(st, 0x3f, sizeof(st));
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int gg = fset(id[i][j]);
      if (g[gg] && id[i][j] == gg) q.push(gg), st[gg] = 0;
      for (int k = 0; k < 4; ++k) {
        int x = dx[k] + i, y = dy[k] + j;
        if (!x || !y || x > n || y > m) continue;
        if (!g[id[x][y]]) e[gg].push_back(fset(id[x][y]));
      }
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : e[u])
      if (st[v] > st[u] + 1) st[v] = st[u] + 1, q.push(v);
  }
  while (t--) {
    int x, y;
    long long p;
    scanf("%d%d%lld", &x, &y, &p);
    int gg = fset(id[x][y]);
    if (st[gg] == st[0] || p <= st[gg])
      printf("%c\n", s[x][y]);
    else {
      p -= st[gg];
      printf("%d\n", (s[x][y] - '0') ^ (p & 1));
    }
  }
}
