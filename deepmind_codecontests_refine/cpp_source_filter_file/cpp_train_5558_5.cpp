#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int INF = 0x3f3f3f3f;
struct node {
  int x, y;
  int op;
  bool operator<(const node &a) const {
    if (x != a.x) return x < a.x;
    if (y != a.y) return y < a.y;
    return op < a.op;
  }
  node(){};
  node(int _x, int _y, int _op) { x = _x, y = _y, op = _op; }
} a[maxn], tmp[maxn];
int cnt;
int n, L, W;
struct EDGE {
  int v, w, nxt;
} edge[maxn << 1];
int head[maxn];
int tot;
void add_edge(int u, int v, int w) {
  edge[tot].v = v;
  edge[tot].w = w;
  edge[tot].nxt = head[u];
  head[u] = tot++;
}
int sz[maxn], vis[maxn], mx[maxn];
int get_root(int u, int fa, int num) {
  int y = 0;
  mx[u] = 0;
  sz[u] = 1;
  for (int i = head[u]; i != -1; i = edge[i].nxt) {
    int v = edge[i].v;
    if (!vis[v] && v != fa) {
      int z = get_root(v, u, num);
      sz[u] += sz[v];
      mx[u] = max(mx[u], sz[v]);
      if (mx[y] > mx[z]) y = z;
    }
  }
  mx[u] = max(mx[u], num - sz[u]);
  return mx[u] < mx[y] ? u : y;
}
void dfs(int u, int fa, int len, int weight) {
  a[++cnt] = node(len, weight, 0);
  a[++cnt] = node(L - len, W - weight, 1);
  for (int i = head[u]; i != -1; i = edge[i].nxt) {
    int v = edge[i].v;
    if (!vis[v] && v != fa) {
      dfs(v, u, len + 1, weight + edge[i].w);
    }
  }
}
long long cdq(int l, int r) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  long long ans = cdq(l, mid) + cdq(mid + 1, r);
  int p = l, q = mid + 1, res = 0;
  for (int i = l; i <= r; i++) {
    if ((p <= mid &&
         (a[p].y < a[q].y || (a[p].y == a[q].y && a[p].op <= a[q].op))) ||
        q > r) {
      res += a[p].op ^ 1;
      tmp[i] = a[p++];
    } else {
      ans += a[q].op * res;
      tmp[i] = a[q++];
    }
  }
  for (int i = l; i <= r; i++) {
    a[i] = tmp[i];
  }
  return ans;
}
long long Find(int u, int len, int weight) {
  long long res = 0;
  cnt = 0;
  dfs(u, 0, len, weight);
  sort(a + 1, a + cnt + 1);
  for (int i = 1; i <= cnt; i++) {
    if (2 * a[i].x <= L && 2 * a[i].y <= W) res += a[i].op ^ 1;
  }
  return (cdq(1, cnt) - res) / 2;
}
long long solve(int u, int num) {
  int root = get_root(u, 0, num);
  long long res = Find(root, 0, 0);
  vis[root] = 1;
  for (int i = head[u]; i != -1; i = edge[i].nxt) {
    int v = edge[i].v, w = edge[i].w;
    if (!vis[v]) {
      res -= Find(v, 1, w);
      res += solve(v, sz[v] > sz[root] ? num - sz[root] : sz[v]);
    }
  }
  return res;
}
int main() {
  mx[0] = INF;
  memset(head, -1, sizeof(head));
  tot = 0;
  scanf("%d%d%d", &n, &L, &W);
  for (int i = 2; i <= n; i++) {
    int u, w;
    scanf("%d%d", &u, &w);
    add_edge(i, u, w);
    add_edge(u, i, w);
  }
  printf("%lld\n", solve(1, n));
  return 0;
}
