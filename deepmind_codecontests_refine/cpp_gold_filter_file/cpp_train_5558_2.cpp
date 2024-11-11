#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to, next, w;
} edge[100100 * 2];
int head[100100], tot;
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w) {
  edge[tot].to = v;
  edge[tot].w = w;
  edge[tot].next = head[u];
  head[u] = tot++;
}
int n, L, W;
bool vis[100100];
int siz[100100];
struct Node {
  int dep;
  long long w;
  Node(int _dep = 0, long long _w = 0) : dep(_dep), w(_w) {}
  bool operator<(const Node& nn) const { return w < nn.w; }
} node[100100];
int le, ri;
int dfs_siz(int u, int pre) {
  siz[u] = 1;
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == pre || vis[v]) continue;
    siz[u] += dfs_siz(v, u);
  }
  return siz[u];
}
int minn;
void get_root(int u, int pre, int totnum, int& root) {
  int maxx = totnum - siz[u];
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == pre || vis[v]) continue;
    get_root(v, u, totnum, root);
    maxx = max(maxx, siz[v]);
  }
  if (maxx < minn) {
    minn = maxx;
    root = u;
  }
}
void dfs_dep(int u, int pre, int d, long long w) {
  node[ri++] = Node(d, w);
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == pre || vis[v]) continue;
    dfs_dep(v, u, d + 1, w + edge[i].w);
  }
}
int bit[100100];
int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & (-i);
  }
  return s;
}
void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & (-i);
  }
}
long long get_dep(int a, int b) {
  sort(node + a, node + b);
  for (int i = a; i < b; ++i) add(node[i].dep, 1);
  long long ret = 0;
  int e = b - 1;
  for (int i = a; i < b; ++i) {
    if (node[i].w > W) break;
    while (e >= a && node[i].w + node[e].w > W) add(node[e].dep, -1), e--;
    ret += sum(L - node[i].dep);
    if (node[i].dep * 2 <= L && node[i].w * 2 <= W) ret--;
  }
  for (int i = e; i >= a; --i) add(node[i].dep, -1);
  return ret / 2LL;
}
long long solve(int root) {
  int totnum = dfs_siz(root, -1);
  long long ret = 0;
  minn = 0x3f3f3f3f;
  get_root(root, -1, totnum, root);
  vis[root] = true;
  for (int i = head[root]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if (vis[v]) continue;
    ret += solve(v);
  }
  le = ri = 0;
  for (int i = head[root]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    if (vis[v]) continue;
    dfs_dep(v, root, 1, edge[i].w);
    ret -= get_dep(le, ri);
    le = ri;
  }
  ret += get_dep(0, ri);
  for (int i = 0; i < ri; ++i) {
    if (node[i].w <= W)
      ret += node[i].dep <= L ? 1 : 0;
    else
      break;
  }
  vis[root] = false;
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &L, &W);
  memset(bit, 0, sizeof(bit));
  init();
  int u, v;
  for (int i = 2; i <= n; ++i) {
    scanf("%d%d", &u, &v);
    addedge(i, u, v);
    addedge(u, i, v);
  }
  memset(vis, false, sizeof(vis));
  printf("%lld\n", solve(1));
  return 0;
}
