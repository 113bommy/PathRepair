#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
vector<int> G[N];
int sz[N], n;
void predfs(int rt, int f) {
  sz[rt] = 1;
  for (int v : G[rt]) {
    if (v != f) predfs(v, rt), sz[rt] += sz[v];
  }
}
int son[N], fa[N];
void dfs(int rt, int f) {
  if (sz[rt] <= n / 2) son[rt] = sz[rt];
  for (int v : G[rt]) {
    if (v == f) continue;
    dfs(v, rt);
    son[rt] = max(son[rt], son[v]);
  }
}
void dfs1(int rt, int f, int ss) {
  if ((n - sz[rt]) <= n / 2) fa[rt] = n - sz[rt];
  fa[rt] = max(fa[rt], ss);
  int mx1 = fa[rt], id1 = 0, mx2 = fa[rt], id2 = 0;
  for (int v : G[rt]) {
    if (v == f) continue;
    if (son[v] >= mx1) {
      mx2 = mx1, id2 = id1;
      mx1 = son[v], id1 = v;
    } else if (son[v] >= mx2) {
      mx2 = son[v], id2 = v;
    }
  }
  for (int v : G[rt]) {
    if (v == f) continue;
    if (v != id1) {
      dfs1(v, rt, mx1);
    } else {
      dfs1(v, rt, mx2);
    }
  }
}
int ans[N];
void solve(int rt, int f) {
  if (f && n - sz[f] - fa[f] > n / 2) ans[rt] = 0;
  for (int v : G[rt]) {
    if (v == f) continue;
    if (sz[v] - son[v] > n / 2) ans[rt] = 0;
    solve(v, rt);
  }
}
int main(int argc, const char* argv[]) {
  scanf("%d", &n);
  for (int u, v, i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  predfs(1, 0);
  dfs(1, 0);
  dfs1(1, 0, 0);
  for (int i = 1; i <= n; ++i) ans[i] = 1;
  solve(1, 0);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
