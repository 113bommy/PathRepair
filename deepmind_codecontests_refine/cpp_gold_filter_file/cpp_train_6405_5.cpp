#include <bits/stdc++.h>
using namespace std;
int dfn[600100], low[600100], id, S[600100], tp[600100], ins[600100],
    he[600100], ne[600100 << 1], e[600100 << 1], cnt = 1, BCC, s[600100],
                                                 p[600100], rt[600100];
int He[600100], Ne[600100 << 1], E[600100 << 1],
    Cnt = 1, bel[600100], Bel[600100], dep[600100], son[600100], nn, sz[600100],
    fa[600100], vis[600100], tot, TOT, top, tt[600100], n, m, Q, R;
inline int read() {
  char ch = getchar();
  int x = 0;
  for (; ch > '9' || ch < '0'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x;
}
void tarjan(int x, int p) {
  dfn[x] = low[x] = ++id;
  S[++top] = x;
  ins[x] = 1;
  for (int i = he[x]; i; i = ne[i]) {
    if (i == (p ^ 1)) continue;
    if (!dfn[e[i]])
      tarjan(e[i], i), low[x] = min(low[x], low[e[i]]);
    else if (ins[e[i]])
      low[x] = min(low[x], dfn[e[i]]);
  }
  if (low[x] == dfn[x]) {
    BCC++;
    int t = 0;
    while (t != x) {
      t = S[top--];
      ins[t] = 0;
      bel[t] = BCC;
    }
  }
}
void Add(int u, int v) {
  Ne[++Cnt] = He[u];
  He[u] = Cnt;
  E[Cnt] = v;
}
void rebuild() {
  for (int x = 1; x <= nn; x++)
    for (int i = he[x]; i; i = ne[i])
      if (bel[x] < bel[e[i]]) Add(bel[x], bel[e[i]]), Add(bel[e[i]], bel[x]);
}
void dfs(int x) {
  dep[x] = dep[fa[x]] + 1;
  sz[x] = 1;
  son[x] = 0;
  for (int i = he[x]; i; i = ne[i]) {
    if (e[i] == fa[x]) continue;
    fa[e[i]] = x;
    dfs(e[i]);
    sz[x] += sz[e[i]];
    if (sz[e[i]] > sz[son[x]]) son[x] = e[i];
  }
}
void dfs(int x, int top, int rot) {
  rt[x] = rot;
  tp[x] = top;
  dfn[x] = ++id;
  if (son[x]) dfs(son[x], top, rot);
  for (int i = he[x]; i; i = ne[i])
    if (e[i] != fa[x] && e[i] != son[x]) dfs(e[i], e[i], rot);
}
void addE(int u, int v) {
  Ne[++Cnt] = He[u];
  He[u] = Cnt;
  E[Cnt] = v;
  Ne[++Cnt] = He[v];
  He[v] = Cnt;
  E[Cnt] = u;
}
int LCA(int a, int b) {
  for (; tp[a] != tp[b]; a = fa[tp[a]])
    if (dep[tp[a]] < dep[tp[b]]) swap(a, b);
  return dep[a] < dep[b] ? a : b;
}
void Ins(int x) {
  if (top <= 1) {
    S[++top] = x;
    vis[++TOT] = x;
    return;
  }
  int lca = LCA(x, S[top]);
  if (S[top] == lca) {
    S[++top] = x;
    vis[++TOT] = x;
    return;
  }
  for (; top > 1 && dfn[S[top - 1]] >= dfn[lca]; top--)
    addE(S[top - 1], S[top]);
  if (S[top] != lca) addE(lca, S[top]), S[top] = lca, vis[++TOT] = lca;
  S[++top] = x;
  vis[++TOT] = x;
}
void build() {
  for (int i = 1; i <= tot; i++) {
    if (rt[s[i]] != rt[s[i - 1]]) {
      for (; top > 1; top--) addE(S[top - 1], S[top]);
      top = 0;
      if (rt[s[i]] != s[i]) Ins(rt[s[i]]);
    }
    Ins(s[i]);
  }
  for (; top > 1; top--) addE(S[top - 1], S[top]);
}
void tarjan2(int x, int p) {
  tt[x] = low[x] = ++id;
  S[++top] = x;
  ins[x] = 1;
  for (int i = He[x]; i; i = Ne[i]) {
    if (i == (p ^ 1)) continue;
    if (!tt[E[i]])
      tarjan2(E[i], i), low[x] = min(low[x], low[E[i]]);
    else if (ins[E[i]])
      low[x] = min(low[x], tt[E[i]]);
  }
  if (tt[x] == low[x]) {
    BCC++;
    int t = 0;
    for (; t != x;) {
      t = S[top--];
      ins[t] = 0;
      Bel[t] = BCC;
    }
  }
}
bool cmp(const int &a, const int &b) { return dfn[a] < dfn[b]; }
void solve(int Id) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    s[++tot] = read();
    s[tot] = (s[tot] + R - 1) % nn + 1;
    s[tot] = p[i] = bel[s[tot]];
  }
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    u = (u + R - 1) % nn + 1;
    v = (v + R - 1) % nn + 1;
    u = bel[u];
    v = bel[v];
    s[++tot] = u;
    s[++tot] = v;
    addE(u, v);
  }
  sort(s + 1, s + 1 + tot, cmp);
  tot = unique(s + 1, s + 1 + tot) - s - 1;
  build();
  id = 0;
  top = 0;
  for (int i = 1; i <= TOT; i++) {
    if (!tt[vis[i]]) tarjan2(vis[i], -1);
  }
  bool flag = 1;
  for (int i = 2; i <= n; i++)
    if (Bel[p[i]] != Bel[p[1]]) flag = 0;
  if (flag)
    puts("YES"), (R += Id) %= nn;
  else
    puts("NO");
  for (int i = 1; i <= TOT; i++) {
    int t = vis[i];
    tt[t] = low[t] = Bel[t] = s[t] = He[t] = 0;
    vis[i] = 0;
  }
  Cnt = 1;
  tot = 0;
  TOT = 0;
  BCC = 0;
  top = 0;
}
void add(int u, int v) {
  ne[++cnt] = he[u];
  he[u] = cnt;
  e[cnt] = v;
}
int main() {
  nn = read(), m = read(), Q = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    if (u == v) continue;
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= nn; i++)
    if (!dfn[i]) tarjan(i, -1);
  rebuild();
  memcpy(he, He, sizeof(He));
  memcpy(ne, Ne, sizeof(Ne));
  memcpy(e, E, sizeof(E));
  memset(dfn, 0, sizeof(dfn));
  memset(He, 0, sizeof(He));
  Cnt = 1;
  for (int i = 1; i <= BCC; i++) {
    if (!dfn[i]) {
      dfs(i);
      dfs(i, i, i);
    }
  }
  BCC = 0;
  memset(low, 0, sizeof(low));
  for (int i = 1; i <= Q; i++) {
    solve(i);
  }
  return 0;
}
