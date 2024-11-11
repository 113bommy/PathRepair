#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;
inline int read() {
  int res = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    res = (res << 3) + (res << 1) + ch - '0';
    ch = getchar();
  }
  return f ? (~res + 1) : res;
}
inline int min(int a, int b) { return a < b ? a : b; }
struct Graph {
  struct Sakura {
    int to, nxt;
  } sak[100005 << 1];
  int head[100005], cnt;
  inline void add(int x, int y) {
    ++cnt;
    sak[cnt].to = y, sak[cnt].nxt = head[x], head[x] = cnt;
  }
} G1;
int n, m, k;
struct DIV {
  int size[100005], son[100005], dep[100005], f[100005];
  inline void dfs_1(int u, int fa) {
    f[u] = fa;
    size[u] = 1;
    dep[u] = dep[fa] + 1;
    for (int i = G1.head[u]; i; i = G1.sak[i].nxt) {
      int v = G1.sak[i].to;
      if (v == fa) continue;
      dfs_1(v, u);
      size[u] += size[v];
      if (size[v] > size[son[u]]) son[u] = v;
    }
  }
  int id[100005], top[100005], tot;
  inline void dfs_2(int u, int topf) {
    top[u] = topf;
    id[u] = ++tot;
    if (!son[u]) return;
    dfs_2(son[u], topf);
    for (int i = G1.head[u]; i; i = G1.sak[i].nxt) {
      int v = G1.sak[i].to;
      if (v == f[u] || v == son[u]) continue;
      dfs_2(v, v);
    }
  }
  inline int lca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) swap(u, v);
      u = f[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
  }
} dv;
int a[1005];
inline bool cmp(const int &a, const int &b) { return dv.id[a] < dv.id[b]; }
int mark[100005], ans;
inline void clear() {
  G1.cnt = ans = 0;
  for (int i = 1; i <= k; ++i) mark[a[i]] = 0;
}
int sta[1005], top;
inline void inserts(int x) {
  if (top == 0) {
    sta[top = 1] = x;
    return;
  }
  int lca = dv.lca(x, sta[top]);
  while (top > 1 && dv.dep[lca] < dv.dep[sta[top - 1]])
    G1.add(sta[top - 1], sta[top]), --top;
  if (dv.dep[lca] < dv.dep[sta[top]]) G1.add(lca, sta[top--]);
  if ((!top) || (sta[top] != lca)) sta[++top] = lca;
  sta[++top] = x;
}
inline void dp(int u) {
  if (mark[u]) {
    for (int i = G1.head[u]; i; i = G1.sak[i].nxt) {
      int v = G1.sak[i].to;
      dp(v);
      if (mark[v]) {
        mark[v] = 0;
        ans++;
      }
    }
  } else {
    for (int i = G1.head[u]; i; i = G1.sak[i].nxt) {
      int v = G1.sak[i].to;
      dp(v);
      mark[u] += mark[v];
      mark[v] = 0;
    }
    if (mark[u] > 1) {
      ans++;
      mark[u] = 0;
    }
  }
  G1.head[u] = 0;
}
int main() {
  n = read();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read();
    G1.add(u, v), G1.add(v, u);
  }
  dv.dfs_1(1, 0);
  dv.dfs_2(1, 1);
  memset(G1.head, 0, sizeof G1.head);
  G1.cnt = 0;
  m = read();
  while (m--) {
    clear();
    k = read();
    for (int i = 1; i <= k; ++i) a[i] = read();
    for (int i = 1; i <= k; ++i) mark[a[i]] = 1;
    bool flag = 0;
    for (int i = 1; i <= k; ++i) {
      if (mark[dv.f[a[i]]] == 1) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      printf("-1\n");
      continue;
    }
    sort(a + 1, a + 1 + k, cmp);
    if (a[1] != 1) sta[top = 1] = 1;
    for (int i = 1; i <= k; ++i) inserts(a[i]);
    while (top) G1.add(sta[top - 1], sta[top]), --top;
    dp(1);
    mark[1] = 0;
    printf("%d\n", ans);
  }
  return 0;
}
