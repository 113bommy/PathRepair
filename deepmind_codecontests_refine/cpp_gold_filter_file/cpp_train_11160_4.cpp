#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int deg[500010];
int head[500010], nxt[500010 * 2], to[500010 * 2], tot;
void add(int u, int v) {
  tot++;
  nxt[tot] = head[u];
  head[u] = tot;
  to[tot] = v;
}
int dep[500010], up[500010][22], fa_id[500010], fa[500010];
void dfs(int x, int las) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == las) continue;
    fa[to[i]] = x;
    dep[to[i]] = dep[x] + 1;
    up[to[i]][0] = x;
    fa_id[to[i]] = (i + 1) / 2;
    dfs(to[i], x);
  }
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 20; i >= 0; i--)
    if (dep[y] + (1 << i) <= dep[x]) x = up[x][i];
  if (x == y) return x;
  for (int i = 20; i >= 0; i--)
    if (up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
  return up[x][0];
}
int get_dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[LCA(x, y)]; }
int a[500010];
int en[500010], st[500010];
vector<pair<int, int> > E[500010];
vector<int> V, e[500010];
int get_path(int x, int lca, int ty) {
  if (x == lca) return 0;
  while (fa[x] != lca) {
    int y = fa[x];
    if (!ty)
      E[y].push_back(make_pair(fa_id[x], fa_id[fa[x]]));
    else
      E[y].push_back(make_pair(fa_id[fa[x]], fa_id[x]));
    x = y;
  }
  return x;
}
int deg_in[500010], deg_out[500010], col[500010];
bool check() {
  for (int i = 0; i < V.size(); i++)
    if (deg[V[i]] > 2) return true;
  return false;
}
queue<int> q;
bool top_sort(int id) {
  for (int i = 0; i < V.size(); i++) deg[V[i]] = 0;
  for (int i = 0; i < E[id].size(); i++) deg[E[id][i].second]++;
  for (int i = 0; i < V.size(); i++)
    if (!deg[V[i]]) q.push(V[i]), col[V[i]] = V[i];
  int cnt = 0;
  while (q.size()) {
    int now = q.front();
    q.pop();
    cnt++;
    for (int i = 0; i < e[now].size(); i++) {
      deg[e[now][i]]--;
      if (!deg[e[now][i]]) col[e[now][i]] = col[now], q.push(e[now][i]);
    }
  }
  return (cnt != V.size());
}
int fac[500010];
int solve(int id) {
  V.clear();
  for (int i = head[id]; i; i = nxt[i]) V.push_back((i + 1) >> 1);
  for (int i = 0; i < V.size(); i++)
    deg_in[V[i]] = deg_out[V[i]] = deg[V[i]] = 0;
  for (int i = 0; i < V.size(); i++) e[V[i]].clear();
  for (int i = 0; i < E[id].size(); i++) {
    deg_out[E[id][i].first]++, deg_in[E[id][i].second]++;
    deg[E[id][i].first]++, deg[E[id][i].second]++;
    e[E[id][i].first].push_back(E[id][i].second);
  }
  if (check()) puts("0"), exit(0);
  if (top_sort(id)) puts("0"), exit(0);
  if (st[id] && deg_in[st[id]]) puts("0"), exit(0);
  if (en[id] && deg_out[en[id]]) puts("0"), exit(0);
  int cnt = 0;
  for (int i = 0; i < V.size(); i++)
    if (!deg_in[V[i]]) cnt++;
  if (st[id] && en[id] && col[st[id]] == col[en[id]]) {
    if (cnt == 1)
      return 1;
    else
      puts("0"), exit(0);
  }
  return fac[cnt - (st[id] != 0) - (en[id] != 0)];
}
int ans = 1;
int main() {
  n = read();
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % 1000000007;
  for (int i = 1; i < n; i++) {
    int q = read(), w = read();
    add(q, w);
    add(w, q);
  }
  dfs(1, 0);
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) up[i][j] = up[up[i][j - 1]][j - 1];
  for (int i = 1; i <= n; i++) a[i] = read();
  long long sum = 0;
  for (int i = 1; i <= n; i++)
    if (a[i]) sum += get_dis(i, a[i]);
  if (sum > 2 * n - 2) return puts("0"), 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      if (i == a[i]) return puts("0"), 0;
      int lca = LCA(i, a[i]);
      int u = get_path(a[i], lca, 0);
      int v = get_path(i, lca, 1);
      if (lca != i && lca != a[i])
        E[lca].push_back(make_pair(fa_id[u], fa_id[v]));
      if (st[a[i]] || en[i]) return puts("0"), 0;
      if (lca == a[i])
        st[a[i]] = fa_id[v];
      else
        st[a[i]] = fa_id[a[i]];
      if (lca == i)
        en[i] = fa_id[u];
      else
        en[i] = fa_id[i];
    }
  }
  for (int i = 1; i <= n; i++) ans = 1ll * ans * solve(i) % 1000000007;
  cout << ans << endl;
  return 0;
}
