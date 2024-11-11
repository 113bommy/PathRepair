#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int n;
vector<int> g[MAXN];
int dfn[MAXN];
int low[MAXN];
int vis[MAXN];
int ins[MAXN];
int ind = 1;
stack<int> st;
int cyc[MAXN];
int ans1 = 0, ans2 = 0;
void dfs(int u) {
  dfn[u] = low[u] = ind++;
  st.push(u);
  ins[u] = vis[u] = 1;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    int t = 0;
    int v;
    do {
      v = st.top();
      st.pop();
      t++;
      ins[v] = 0;
    } while (u != v);
    if (t > 1) cyc[u] = 1;
  }
}
void get_scc() {
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
}
int p[MAXN];
int cnt[MAXN];
void init() {
  for (int i = 1; i <= n; i++) {
    cnt[i] = 1;
    p[i] = i;
  }
}
int query(int x) { return p[x] == x ? x : p[x] = query(p[x]); }
void merge(int x, int y) {
  x = query(x);
  y = query(y);
  if (x == y) {
    return;
  }
  p[x] = y;
  cyc[y] |= cyc[x];
  cnt[y] += cnt[x];
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  init();
  get_scc();
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      merge(u, v);
    }
  }
  int ans;
  for (int u = 1; u <= n; u++)
    if (p[u] == u) {
      ans += cnt[u] - 1 + cyc[u];
    }
  printf("%d\n", ans);
  return 0;
}
