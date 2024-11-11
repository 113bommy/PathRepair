#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
typedef struct edge {
  int v, nxt;
} edge;
edge save[maxn * 3];
int last[maxn];
int tot;
void init() {
  tot = 0;
  memset(last, -1, sizeof(last));
}
void adde(int u, int v) {
  save[tot].v = v;
  save[tot].nxt = last[u];
  last[u] = tot++;
  save[tot].v = u;
  save[tot].nxt = last[v];
  last[v] = tot++;
}
int flec[maxn];
int range[maxn];
int tsz;
int fth[maxn];
int n, m;
int vis[maxn];
void dfs(int root) {
  vis[root] = 1;
  flec[root] = tsz++;
  int i;
  for (i = last[root]; i != -1; i = save[i].nxt) {
    int v = save[i].v;
    if (vis[v]) continue;
    fth[v] = root;
    dfs(v);
  }
  range[root] = tsz - 1;
}
vector<int> query[maxn];
typedef struct node {
  int l, r;
  int cover;
  int len;
} node;
node t[maxn * 4];
void build(int root, int l, int r) {
  t[root].l = l;
  t[root].r = r;
  t[root].cover = 0;
  t[root].len = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(((root) << 1), l, mid);
  build(((root) << 1 | 1), mid + 1, r);
}
inline int cmax(int a, int b) { return a > b ? a : b; }
void update(int root) {
  if (t[root].cover) {
    t[root].len = t[root].r - t[root].l + 1;
  } else {
    t[root].len = t[((root) << 1)].len + t[((root) << 1 | 1)].len;
  }
}
void add(int root, int l, int r, int val) {
  if (l == t[root].l && r == t[root].r) {
    t[root].cover += val;
    update(root);
    return;
  }
  int mid = (t[root].l + t[root].r) >> 1;
  if (l > mid) {
    add(((root) << 1 | 1), l, r, val);
  } else if (r < mid + 1) {
    add(((root) << 1), l, r, val);
  } else {
    add(((root) << 1), l, mid, val);
    add(((root) << 1 | 1), mid + 1, r, val);
  }
  update(root);
}
int res[maxn];
void dfs2(int root) {
  vis[root] = 1;
  int i;
  int lsz = query[root].size();
  for (i = 0; i < lsz; i++) {
    add(1, flec[query[root][i]], range[query[root][i]], 1);
  }
  res[root] = t[1].len > 0 ? t[1].len - 1 : t[1].len;
  for (i = last[root]; i != -1; i = save[i].nxt) {
    if (vis[save[i].v]) continue;
    dfs2(save[i].v);
  }
  for (i = 0; i < lsz; i++) {
    add(1, flec[query[root][i]], range[query[root][i]], -1);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  int i;
  int u, v;
  init();
  for (i = 1; i < n; i++) {
    cin >> u >> v;
    adde(u, v);
  }
  memset(vis, 0, sizeof(vis));
  tsz = 1;
  dfs(1);
  memset(vis, 0, sizeof(vis));
  for (i = 0; i < m; i++) {
    cin >> u >> v;
    query[u].push_back(v);
    query[v].push_back(u);
    vis[u] = vis[v] = 1;
  }
  for (i = 1; i <= n; i++) {
    if (vis[i]) {
      query[i].push_back(i);
    }
    sort(query[i].begin(), query[i].end());
    query[i].erase(unique(query[i].begin(), query[i].end()), query[i].end());
  }
  memset(vis, 0, sizeof(vis));
  build(1, 1, n);
  dfs2(1);
  for (i = 1; i <= n; i++) {
    cout << res[i] << endl;
  }
  return 0;
}
