#include <bits/stdc++.h>
using namespace std;
const int MAXN = 222222;
int n, m, k, rnk[MAXN];
int imp;
vector<int> fwd[MAXN], bwd[MAXN];
int T, vis[MAXN], ret[MAXN];
int tp, topo[MAXN];
int lo[MAXN], hi[MAXN];
int idx[MAXN];
int ans[MAXN];
priority_queue<pair<int, int> > que;
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a < b ? b : a; }
inline void addEdge(int u, int v) {
  fwd[u].push_back(v);
  bwd[v].push_back(u);
}
void dfs(int u) {
  vis[u] = ++T;
  for (auto v : fwd[u]) {
    if (!vis[v]) {
      dfs(v);
    } else {
      imp |= !ret[v];
    }
    if (imp) break;
  }
  ret[u] = T;
  topo[++tp] = u;
}
inline void reverse(int a[], int u, int v) {
  for (int i = u, j = v; i < j; ++i, --j) {
    a[i] ^= a[j], a[j] ^= a[i], a[i] ^= a[j];
  }
}
int cmp(int u, int v) { return hi[u] > hi[v]; }
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", rnk + i);
  for (int i = 1, u, v; i <= n; ++i) {
    scanf("%d%d", &u, &v);
    addEdge(u, v);
  }
  imp = 0;
  memset(vis, 0, sizeof(vis));
  memset(ret, 0, sizeof(ret));
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      dfs(i);
      if (imp) break;
    }
  if (imp) {
    printf("-1\n");
    return 0;
  }
  reverse(topo, 1, n);
  for (int i = 1; i <= n; ++i) {
    if (rnk[i]) {
      lo[i] = hi[i] = rnk[i];
    } else {
      lo[i] = 1, hi[i] = k;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int v = topo[i];
    for (auto u : bwd[v]) {
      hi[v] = min(hi[v], hi[u] - 1);
    }
    if (lo[v] > hi[v]) {
      imp = 1;
      break;
    }
  }
  if (imp) {
    printf("-1\n");
    return 0;
  }
  for (int i = n; i; --i) {
    int u = topo[i];
    for (auto v : fwd[u]) {
      lo[u] = max(lo[u], lo[v] + 1);
    }
    if (lo[u] > hi[u]) {
      imp = 1;
      break;
    }
  }
  if (imp) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
  }
  for (int i = 1; i <= n; ++i) idx[i] = i;
  sort(idx + 1, idx + n + 1, cmp);
  for (int i = k, j = 1; i; --i) {
    for (; j && hi[idx[j]] >= i; ++j) {
      que.push(pair<int, int>(lo[idx[j]], idx[j]));
    }
    for (; !que.empty() && que.top().first > i; que.pop())
      ;
    if (que.empty()) {
      imp = 1;
      break;
    }
    int u = que.top().second;
    que.pop();
    ans[u] = i;
    lo[u] = hi[u] = i;
  }
  if (imp) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    int v = topo[i];
    for (auto u : bwd[v]) {
      hi[v] = min(hi[v], hi[u] - 1);
    }
  }
  for (int i = n; i; --i) {
    int u = topo[i];
    for (auto v : fwd[u]) {
      lo[u] = max(lo[u], lo[v] + 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!ans[i]) {
      ans[i] = hi[i];
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  printf("\n");
}
