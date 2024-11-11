#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<pair<int, int> > g[N];
vector<int> G[N];
int n, m;
int color[N], cols, anss[3];
vector<int> ansn, tmpans, tmpanss[2];
vector<int> component[N];
int ans, pra, sz[N], vis[N], black[N];
void dfs(int u, int f) {
  color[u] = cols;
  sz[cols]++;
  component[cols].push_back(u);
  vis[u] = 1;
  for (pair<int, int> vv : g[u]) {
    if (vv.second != pra) continue;
    int v = vv.first;
    if (v == f) continue;
    dfs(v, u);
  }
}
int rebuild() {
  for (int i = 1; i <= cols; ++i) G[i].clear();
  for (int u = 1; u <= n; ++u) {
    for (pair<int, int> vv : g[u]) {
      if (vv.second == pra) continue;
      int v = vv.first;
      if (color[v] == color[u]) return 0;
      G[color[u]].push_back(color[v]);
    }
  }
  return 1;
}
int check(int u, int f, int flag) {
  if (black[u] != 0) return black[u] == flag;
  int res = 1;
  black[u] = flag;
  tmpanss[flag].push_back(u);
  anss[flag] += sz[u];
  for (int v : G[u]) {
    res &= check(v, u, 3 - flag);
  }
  return res;
}
void solve(int para) {
  pra = para;
  cols = 0;
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == 0) {
      cols++;
      component[cols].clear();
      sz[cols] = 0;
      dfs(i, -1);
    }
  }
  int ok = rebuild();
  int res = 0;
  memset(black, 0, sizeof black);
  tmpans.clear();
  for (int i = 1; i <= cols && ok; ++i) {
    if (black[i] != 0) continue;
    tmpanss[1].clear();
    tmpanss[2].clear();
    anss[1] = anss[2] = 0;
    ok &= check(i, -1, 1);
    int pos = 1;
    if (anss[1] > anss[2]) pos = 2;
    res += min(anss[1], anss[2]);
    for (int v : tmpanss[pos]) {
      for (int vv : component[v]) {
        tmpans.push_back(vv);
      }
    }
  }
  if (ok == 0) return;
  if (res < ans) {
    ans = res;
    ansn.clear();
    for (int v : tmpans) ansn.push_back(v);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    char s[10];
    int x, y;
    scanf("%d %d %s", &x, &y, s);
    int col = s[0] == 'R';
    g[x].push_back(make_pair(y, col));
    g[y].push_back(make_pair(x, col));
  }
  ans = n + 1;
  solve(0);
  solve(1);
  if (ans == n + 1)
    puts("-1");
  else {
    printf("%d\n", ans);
    for (int i = 0; i < ansn.size(); ++i) printf("%d ", ansn[i]);
    puts("");
  }
}
