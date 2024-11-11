#include <bits/stdc++.h>
using namespace std;
const int M = 105;
int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') y = (ch == '-') ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * y;
}
int n, a[M], ls[M], rs[M], sz[M], dp[M][3][3];
bool vis[M][3][3];
void dfs(int u) {
  if (a[u] != -1) return sz[u] = 0, void();
  dfs(ls[u]), dfs(rs[u]), sz[u] = sz[ls[u]] + sz[rs[u]] + 1;
  if (sz[rs[u]] & 1) swap(ls[u], rs[u]);
}
int get(int a, int b, int typ) { return typ ? min(a, b) : max(a, b); }
int dfs(int u, int typ, int fl) {
  if (a[u] != -1) return a[u];
  if (sz[u] == 1) return get(a[ls[u]], a[rs[u]], typ ^ (fl == 2));
  if (vis[u][typ][fl]) return dp[u][typ][fl];
  vis[u][typ][fl] = 1;
  int res;
  if (!fl) {
    if (sz[u] & 1) {
      int sth = sz[ls[u]] & 1;
      res = get(dfs(ls[u], typ, sth), dfs(rs[u], typ, sth), typ);
    } else
      res = get(get(dfs(ls[u], typ, 0), dfs(rs[u], !typ, 0), !typ),
                get(dfs(rs[u], typ, 1), dfs(ls[u], !typ, 1), !typ), typ);
  } else {
    if (sz[u] & 1) {
      res = dfs(u, !typ, 0);
      int sth = sz[ls[u]] & 1;
      if (sth || sz[rs[u]])
        res =
            get(res,
                get(dfs(ls[u], 1 ^ typ ^ sth, 0),
                    dfs(rs[u], typ ^ sth, sz[ls[u]] == sth && fl == 1 ? 2 : 1),
                    !typ),
                typ);
      if (sth || sz[ls[u]])
        res =
            get(res,
                get(dfs(rs[u], 1 ^ typ ^ sth, 0),
                    dfs(ls[u], typ ^ sth, sz[rs[u]] == sth && fl == 1 ? 2 : 1),
                    !typ),
                typ);
    } else
      res = get(dfs(rs[u], typ, 0),
                dfs(ls[u], typ, !sz[rs[u]] && fl == 1 ? 2 : 1), typ);
  }
  return dp[u][typ][fl] = res;
}
void solve() {
  memset(vis, 0, sizeof(vis));
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] == -1) ls[i] = read() + 1, rs[i] = read() + 1;
  }
  dfs(1);
  printf("%d\n", dfs(1, 0, 0));
}
signed main() {
  int T = read();
  while (T--) solve();
}
