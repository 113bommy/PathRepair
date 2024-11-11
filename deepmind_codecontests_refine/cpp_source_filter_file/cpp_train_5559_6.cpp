#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
const int maxm = 50005;
struct node_Tp {
  int u, v, d;
  node_Tp(int _u = 0, int _v = 0, int _d = 0) : u(_u), v(_v), d(_d) {}
};
int n, v, m, a[maxn], b[maxn];
int head[maxn], adj[maxm * 2], nxt[maxm * 2], total;
int pre[maxn], que[maxn], path[maxn], top, st, ed;
vector<node_Tp> vec;
inline void addedge(int u, int v) {
  ++total, adj[total] = v, nxt[total] = head[u], head[u] = total;
}
void deliver(int l, int r, int w) {
  if (l == r) return;
  if (a[path[l + 1]] + w <= v) {
    a[path[l]] -= w, a[path[l + 1]] += w;
    vec.push_back(node_Tp(path[l], path[l + 1], w));
    deliver(l + 1, r, w);
  } else {
    deliver(l + 1, r, w);
    a[path[l]] -= w, a[path[l + 1]] += w;
    vec.push_back(node_Tp(path[l], path[l + 1], w));
  }
}
void find_path(int u) {
  memset(pre, -1, sizeof(pre));
  st = 1, ed = 0, que[++ed] = u, pre[u] = 0;
  while (st <= ed && a[u] > b[u]) {
    int u_cur = que[st];
    ++st;
    if (a[u_cur] < b[u_cur]) {
      int w = min(b[u_cur] - a[u_cur], a[u] - b[u]);
      top = 0;
      for (int p = u_cur; p != 0; p = pre[p]) path[++top] = p;
      reverse(path + 1, path + 1 + top);
      if (w <= v / 2)
        deliver(1, top, w);
      else
        deliver(1, top, v / 2), deliver(1, top, w - v / 2);
    }
    for (int i = head[u_cur]; i; i = nxt[i]) {
      if (pre[adj[i]] == -1) {
        pre[adj[i]] = u;
        que[++ed] = adj[i];
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &v, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int x, y, i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    addedge(x, y), addedge(y, x);
  }
  for (int i = 1; i <= n; i++)
    if (a[i] > b[i]) find_path(i);
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i]) {
      puts("NO");
      return 0;
    }
  printf("%d\n", (int)vec.size());
  for (int i = 0; i < (int)vec.size(); i++)
    printf("%d %d %d\n", vec[i].u, vec[i].v, vec[i].d);
  return 0;
}
