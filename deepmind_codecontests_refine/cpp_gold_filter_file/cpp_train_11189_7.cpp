#include <bits/stdc++.h>
using namespace std;
const int N = 100020, Log = 19;
inline int read() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
  return f ? -x : x;
}
struct Edge {
  int to, next, dis;
  Edge() {}
  Edge(int to, int next, int dis) : to(to), next(next), dis(dis) {}
};
int head[N], edge_cnt;
Edge edge[N * 2];
void AddEdge(int x, int y, int w) {
  edge[++edge_cnt] = Edge(y, head[x], w), head[x] = edge_cnt;
  edge[++edge_cnt] = Edge(x, head[y], w), head[y] = edge_cnt;
}
int dis[N];
void dfs(int x, int father) {
  for (int i = head[x]; i; i = edge[i].next) {
    int y = edge[i].to;
    if (y != father) dis[y] = dis[x] + edge[i].dis, dfs(y, x);
  }
}
int n, q;
struct Tree {
  int top[N], bot[N], lson[N], height[N], deep[N];
  int fa[N][Log], Min[N][Log], color[N];
  int chain[N], tot;
  void dfs1(int x, int in) {
    for (int i = head[x]; i; i = edge[i].next) {
      int y = edge[i].to;
      if (y == *fa[x]) continue;
      *fa[y] = x, deep[y] = deep[x] + edge[i].dis, dfs1(y, edge[i].dis);
      if (height[y] > height[x]) height[x] = height[y], lson[x] = y;
    }
    height[x] += in;
  }
  void dfs2(int x, int topf) {
    top[x] = topf;
    if (x == topf) chain[++tot] = x;
    if (lson[x]) {
      dfs2(lson[x], topf);
      bot[x] = bot[lson[x]];
    } else {
      bot[x] = x;
      return;
    }
    for (int i = head[x]; i; i = edge[i].next) {
      int y = edge[i].to;
      if (y == *fa[x] || y == lson[x]) continue;
      dfs2(y, y);
    }
  }
  void dfs3(int x) {
    *Min[x] = color[x];
    for (int i = 1; i < Log; ++i) {
      fa[x][i] = fa[fa[x][i - 1]][i - 1];
      Min[x][i] = min(Min[x][i - 1], Min[fa[x][i - 1]][i - 1]);
    }
    for (int i = head[x]; i; i = edge[i].next) {
      int y = edge[i].to;
      if (y == *fa[x]) continue;
      dfs3(y);
    }
  }
  int jump(int x, int goal) {
    for (int i = Log - 1; ~i; --i)
      if (Min[x][i] > goal) x = fa[x][i];
    return x;
  }
  void set_root(int x) {
    dfs1(x, 0);
    dfs2(x, x);
    sort(chain + 1, chain + 1 + tot,
         [&](int x, int y) { return height[x] > height[y]; });
    for (int i = 1; i <= tot; ++i) {
      for (int j = bot[chain[i]]; j != chain[i]; j = *fa[j]) color[j] = i;
      color[chain[i]] = i;
      chain[i] = chain[i - 1] + height[chain[i]];
    }
    dfs3(x);
  }
  int query(int x, int y) {
    y = min(2 * y - 1, tot);
    if (color[x] <= y) return chain[y];
    int node = jump(x, y);
    return max(chain[y - 1] + height[top[x]] + deep[*fa[top[x]]] - deep[node],
               chain[y] - height[lson[node]] + height[top[x]] +
                   deep[*fa[top[x]]] - deep[node]);
  }
};
Tree a, b;
int main() {
  n = read(), q = read();
  for (int i = 1; i < n; ++i) {
    int x = read(), y = read(), w = read();
    AddEdge(x, y, w);
  }
  dfs(1, -1);
  int _a = max_element(dis + 1, dis + 1 + n) - dis;
  dfs(_a, -1);
  int _b = max_element(dis + 1, dis + 1 + n) - dis;
  a.set_root(_a), b.set_root(_b);
  for (int ans = 0; q; q--) {
    int x = (read() + ans - 1) % n + 1;
    int y = (read() + ans - 1) % n + 1;
    printf("%d\n", ans = max(a.query(x, y), b.query(x, y)));
  }
}
