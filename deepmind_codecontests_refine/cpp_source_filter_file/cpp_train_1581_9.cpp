#include <bits/stdc++.h>
using namespace std;
int T[1000010][30], cnt = 0, fa[1000010];
char s[400010];
struct Q {
  int id, x;
};
int A[400010], val[400010];
vector<Q> g[1000010];
vector<int> gg[1000010];
queue<int> q;
void insert(int id) {
  int f = 0, i, v;
  for (i = 0; s[i]; i++) {
    v = s[i] - 'a';
    if (T[f][v] == 0) T[f][v] = ++cnt;
    f = T[f][v];
  }
  A[id] = f;
}
void build() {
  int i, u, v, p;
  for (i = 0; i < 27; i++)
    if (T[0][i]) q.push(T[0][i]);
  for (; q.size(); q.pop()) {
    u = q.front();
    gg[fa[u]].push_back(u);
    for (i = 0; i < 27; i++) {
      v = T[u][i];
      if (v) {
        p = fa[u];
        while (p && T[p][i] == 0) p = fa[p];
        fa[v] = T[p][i];
        q.push(v);
      }
    }
  }
}
int in[1000010], out[1000010], dfn = 0;
void dfs(int u) {
  int i, v;
  in[u] = ++dfn;
  for (i = 0; i < gg[u].size(); i++) {
    v = gg[u][i];
    dfs(v);
  }
  out[u] = dfn;
}
int sum[1000100], ans[400010];
int lb(int x) { return x & -x; }
void add(int x, int v) {
  for (; x <= 400010; x += lb(x)) sum[x] += v;
}
int qsum(int x) {
  int k = 0;
  for (; x; x -= lb(x)) k += sum[x];
  return k;
}
void dfs1(int u) {
  int i, v;
  add(in[u], 1);
  Q x;
  for (i = 0; i < g[u].size(); i++) {
    x = g[u][i];
    ans[x.id] = qsum(out[x.x]) - qsum(in[x.x] - 1);
  }
  for (i = 0; i < 27; i++)
    if (T[u][i]) dfs1(T[u][i]);
  add(in[u], -1);
}
int main() {
  int i, n, k, v, u, m, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &k);
    if (k == 1) {
      scanf("%s", s);
      v = s[0] - 'a';
      if (T[0][v] == 0) T[0][v] = ++cnt;
      val[i] = T[0][v];
    } else {
      scanf("%d%s", &k, s);
      v = s[0] - 'a';
      u = val[k];
      if (T[u][v] == 0) T[u][v] = ++cnt;
      val[i] = T[u][v];
    }
  }
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%s", &k, s);
    insert(i);
    g[val[k]].push_back(Q({i, A[i]}));
  }
  build();
  dfs(0);
  dfs1(0);
  for (i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
