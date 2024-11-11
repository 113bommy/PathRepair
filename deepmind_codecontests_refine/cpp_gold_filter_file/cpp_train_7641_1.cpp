#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long infLL = 0x3f3f3f3f3f3f3f3fLL;
const int hash_mod = 1000037;
const double pi = acos(-1);
const double eps = 1e-10;
const int maxn = 500 + 2;
const int maxl = 3000000 + 5;
int n, x, y;
bool g[maxn][maxn];
bool vis[maxn][maxn];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
char dir[4] = {'U', 'L', 'R', 'D'};
set<int> r[maxn], c[maxn];
int p;
char res[maxl];
bool go(int x, int y, int d) {
  if (d == 0) return !c[y].empty() && *c[y].begin() < x;
  if (d == 1) return !r[x].empty() && *r[x].begin() < y;
  if (d == 2) return !r[x].empty() && *r[x].rbegin() > y;
  if (d == 3) return !c[y].empty() && *c[y].rbegin() > x;
}
void dfs(int x, int y) {
  for (int i = 0; i < 4; ++i)
    if (go(x, y, i)) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!g[x][y]) {
        g[x][y] = true;
        res[p++] = '1';
      }
      if (!vis[nx][ny]) {
        vis[nx][ny] = true;
        res[p++] = dir[i];
        dfs(nx, ny);
        res[p++] = dir[3 - i];
      }
    }
  if (r[x].count(y)) r[x].erase(y);
  if (c[y].count(x)) c[y].erase(x);
  if (g[x][y]) {
    g[x][y] = false;
    res[p++] = '2';
  }
}
bool ok() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (g[i][j]) return false;
  return true;
}
int main() {
  scanf("%d%d%d", &n, &x, &y);
  --x;
  --y;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      scanf("%d", &g[i][j]);
      if (g[i][j]) {
        r[i].insert(j);
        c[j].insert(i);
      }
    }
  vis[x][y] = true;
  dfs(x, y);
  res[p] = 0;
  if (ok()) {
    puts("YES");
    puts(res);
  } else {
    puts("NO");
  }
  return 0;
}
