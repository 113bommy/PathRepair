#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
struct edge {
  int nxt, to, f;
} e[5000005];
int n, m, cnt = 1, source, sink, dfs_clock, all;
int h[N], id[N], iter[N], d[N], dfn[N], top[N], sz[N], son[N], mir[N], dep[N],
    fa[N], vis[N], A[N], B[N];
vector<int> G[N], ans1, ans2;
map<pair<int, int>, int> mp;
void link(int u, int v, int f) {
  e[++cnt].nxt = h[u];
  h[u] = cnt;
  e[cnt].to = v;
  e[cnt].f = f;
}
void insert(int u, int v, int f) {
  link(u, v, f);
  link(v, u, 0);
}
bool bfs() {
  queue<int> q;
  q.push(source);
  memset(d, -1, sizeof(d));
  d[source] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i; i = e[i].nxt) {
      if (d[e[i].to] == -1 && e[i].f) {
        d[e[i].to] = d[u] + 1;
        q.push(e[i].to);
      }
    }
  }
  return d[sink] != -1;
}
int dfs(int u, int delta) {
  if (u == sink) {
    return delta;
  }
  int ret = 0;
  for (int &i = iter[u]; i; i = e[i].nxt) {
    if (d[e[i].to] == d[u] + 1 && e[i].f) {
      int x = dfs(e[i].to, min(delta, e[i].f));
      e[i].f -= x;
      e[i ^ 1].f += x;
      delta -= x;
      ret += x;
      if (!delta) {
        break;
      }
    }
  }
  return ret;
}
void dfs_get(int u) {
  vis[u] = 1;
  for (int i = h[u]; i; i = e[i].nxt) {
    if (e[i].f && !vis[e[i].to]) {
      dfs_get(e[i].to);
    }
  }
}
int dinic() {
  int ret = 0;
  while (bfs()) {
    for (int i = 1; i <= all; ++i) {
      iter[i] = h[i];
    }
    ret += dfs(source, inf);
  }
  return ret;
}
void Dfs(int u, int last) {
  sz[u] = 1;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v == last) {
      continue;
    }
    fa[v] = u;
    dep[v] = dep[u] + 1;
    Dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) {
      son[u] = v;
    }
  }
}
void dfs(int u, int last, int anc) {
  dfn[u] = ++dfs_clock;
  mir[dfn[u]] = mp[make_pair(u, last)];
  top[u] = anc;
  if (son[u]) {
    dfs(son[u], u, anc);
  }
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v == last || v == son[u]) {
      continue;
    }
    dfs(v, u, v);
  }
}
void build(int l, int r, int x) {
  id[x] = ++all;
  if (l == r) {
    B[mir[l]] = id[x];
    insert(id[x], sink, 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, x << 1);
  build(mid + 1, r, x << 1 | 1);
  insert(id[x], id[x << 1], inf);
  insert(id[x], id[x << 1 | 1], inf);
}
void update(int l, int r, int x, int a, int b, int p) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    insert(p, id[x], inf);
    return;
  }
  int mid = (l + r) >> 1;
  update(l, mid, x << 1, a, b, p);
  update(mid + 1, r, x << 1 | 1, a, b, p);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    mp[make_pair(u, v)] = mp[make_pair(v, u)] = i;
  }
  source = ++all;
  sink = ++all;
  Dfs(1, 0);
  dfs(1, 0, 1);
  build(1, n, 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    A[i] = ++all;
    insert(source, A[i], 1);
    scanf("%d%d", &u, &v);
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) {
        swap(u, v);
      }
      update(1, n, 1, dfn[top[u]], dfn[u], A[i]);
      u = fa[top[u]];
    }
    if (dfn[u] > dfn[v]) {
      swap(u, v);
    }
    if (dfn[u] < dfn[v]) {
      update(1, n, 1, dfn[u] + 1, dfn[v], A[i]);
    }
  }
  printf("%d\n", dinic());
  dfs_get(source);
  for (int i = 1; i <= m; ++i) {
    if (!vis[A[i]]) {
      ans1.push_back(i);
    }
  }
  for (int i = 1; i < n; ++i) {
    if (vis[B[i]]) {
      ans2.push_back(i);
    }
  }
  printf("%d ", (int)(ans1.size()));
  for (int i = 0; i < ans1.size(); ++i) {
    printf("%d ", ans1[i]);
  }
  printf("\n%d ", (int)(ans2.size()));
  for (int i = 0; i < ans2.size(); ++i) {
    printf("%d ", ans2[i]);
  }
  puts("");
  return 0;
}
