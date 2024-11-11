#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 2e5 + 10, M = 1e6 + 10, inf = 2147483647;
const long long INF = 1e18 + 10, mod = 2147493647;
struct is {
  int v, next;
  long long w;
} edge[N << 1];
int head[N], edg;
int in[N], out[N], tot;
long long dis[N], a[N];
void init() {
  memset(head, -1, sizeof(head));
  edg = 0;
  tot = 0;
}
void add(int u, int v, long long w) {
  edg++;
  edge[edg].v = v;
  edge[edg].w = w;
  edge[edg].next = head[u];
  head[u] = edg;
}
void dfs(int u, int fa, long long val) {
  tot++;
  in[u] = tot;
  dis[u] = val;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    long long w = edge[i].w;
    if (v == fa) continue;
    dfs(v, u, val + w);
  }
  out[u] = tot;
}
struct treearray {
  int tree[N];
  void init() { memset(tree, 0, sizeof(tree)); }
  int lowbit(int x) { return x & -x; }
  void update(int x, int c) {
    while (x < N) {
      tree[x] += c;
      x += lowbit(x);
    }
  }
  int query(int x) {
    int sum = 0;
    while (x) {
      sum += tree[x];
      x -= lowbit(x);
    }
    return sum;
  }
};
struct p {
  long long x;
  int pos;
  bool operator<(const p &a) const { return x < a.x; }
} b[N];
struct q {
  int l, r, pos;
  long long x;
  bool operator<(const q &a) const { return x < a.x; }
} q[N];
int ans[N];
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 2; i <= n; i++) {
    int v;
    long long w;
    scanf("%d%lld", &v, &w);
    add(v, i, w);
    add(i, v, w);
  }
  dfs(1, -1, 0LL);
  for (int i = 1; i <= n; i++) b[in[i]].x = dis[i] - a[i], b[i].pos = i;
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    q[i].l = in[i];
    q[i].r = out[i];
    q[i].pos = i;
    q[i].x = dis[i];
  }
  sort(q + 1, q + 1 + n);
  int st = 1;
  treearray tree;
  tree.init();
  for (int i = 1; i <= n; i++) {
    while (st <= q[i].r && q[i].x >= b[st].x) {
      tree.update(b[st].pos, 1);
      st++;
    }
    ans[q[i].pos] = tree.query(q[i].r) - tree.query(q[i].l);
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
