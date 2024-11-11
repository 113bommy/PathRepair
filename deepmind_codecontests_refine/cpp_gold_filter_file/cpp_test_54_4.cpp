#include <bits/stdc++.h>
using namespace std;
const int _ = 500003;
int hd[_], nxt[_ << 2], ver[_ << 2], tot;
bool val[_ << 2], vis[_], col[_];
void add(int u, int v, bool w) {
  nxt[++tot] = hd[u];
  hd[u] = tot;
  ver[tot] = v;
  val[tot] = w;
}
char tmp[10];
int n, m;
int res, bla, whi;
bool flag;
void dfs(int u) {
  vis[u] = 1;
  if (col[u])
    ++bla;
  else
    ++whi;
  for (int i = hd[u]; i; i = nxt[i]) {
    int v = ver[i];
    if (vis[v]) {
      if (col[u] ^ val[i] ^ col[v]) flag = 1;
    } else {
      col[v] = (col[u] ^ val[i]);
      dfs(v);
    }
    if (flag) break;
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  flag = 0;
  res = 0;
  while (tot) nxt[tot] = ver[tot] = val[tot] = 0, --tot;
  for (int i = 1; i <= n; i++) hd[i] = vis[i] = col[i] = 0;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    scanf("%s", tmp);
    if (tmp[0] == 'i')
      add(u, v, 1), add(v, u, 1);
    else
      add(u, v, 0), add(v, u, 0);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      whi = bla = 0;
      dfs(i);
      if (flag) {
        puts("-1");
        return;
      }
      res += max(whi, bla);
    }
  printf("%d\n", res);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
