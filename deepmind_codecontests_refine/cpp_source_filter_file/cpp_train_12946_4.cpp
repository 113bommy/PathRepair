#include <bits/stdc++.h>
using namespace std;
int n, m;
int ecnt;
struct Edge {
  int to;
  Edge *next;
} * mat[100005], edges[100005];
void link(int x, int to) {
  edges[ecnt].to = to;
  edges[ecnt].next = mat[x];
  mat[x] = &edges[ecnt++];
}
int ncnt, size[100005], top[100005], fa[100005], son[100005], dep[100005],
    in_tree[100005], id[100005];
void dfs1(int x, int depth) {
  size[x] = 1, son[x] = -1;
  dep[x] = depth;
  for (Edge *p = mat[x]; p; p = p->next) {
    int to = p->to;
    fa[to] = x;
    dfs1(to, depth + 1);
    size[x] += to;
    if (son[x] == -1 || size[to] > size[son[x]]) son[x] = to;
  }
}
void dfs2(int x, int tp) {
  id[in_tree[x] = ++ncnt] = x;
  top[x] = tp;
  if (son[x] != -1) dfs2(son[x], tp);
  for (Edge *p = mat[x]; p; p = p->next) {
    int to = p->to;
    if (to == son[x]) continue;
    dfs2(to, to);
  }
}
struct Node {
  int left, right;
  int key, ch[2];
} tree[100005 * 30];
int root[100005];
void build(int left, int right, int step) {
  tree[step].left = left;
  tree[step].right = right;
  tree[step].key = 0;
  if (left == right) return;
  int mid = (left + right) / 2;
  tree[step].ch[0] = ++ncnt;
  build(left, mid, tree[step].ch[0]);
  tree[step].ch[1] = ++ncnt;
  build(mid + 1, right, tree[step].ch[1]);
}
void updata(int w, int step, int old) {
  tree[step].ch[0] = tree[old].ch[0];
  tree[step].ch[1] = tree[old].ch[1];
  tree[step].left = tree[old].left, tree[step].right = tree[old].right;
  tree[step].key = tree[old].key + 1;
  if (tree[step].left == tree[step].right) return;
  int mid = (tree[step].left + tree[step].right) / 2;
  if (w <= mid)
    updata(w, tree[step].ch[0] = ++ncnt, tree[old].ch[0]);
  else
    updata(w, tree[step].ch[1] = ++ncnt, tree[old].ch[1]);
}
int ask(int left, int right, int step, int g) {
  if (tree[step].left == left && tree[step].right == right)
    return tree[step].key + (right - left + 1) - tree[g].key;
  int mid = (tree[step].left + tree[step].right) / 2;
  if (right <= mid)
    return ask(left, right, tree[step].ch[0], tree[g].ch[0]);
  else if (left > mid)
    return ask(left, right, tree[step].ch[1], tree[g].ch[1]);
  else
    return ask(left, mid, tree[step].ch[0], tree[g].ch[0]) +
           ask(mid + 1, right, tree[step].ch[1], tree[g].ch[1]);
}
int rank_K(int left, int right, int step, int g, int K) {
  int mid = (tree[step].left + tree[step].right) / 2;
  if (left == right) return left;
  if (right <= mid)
    return rank_K(left, right, tree[step].ch[0], tree[g].ch[0], K);
  else if (left > mid)
    return rank_K(left, right, tree[step].ch[1], tree[g].ch[1], K);
  else {
    int num = ask(left, mid, tree[step].ch[0], tree[g].ch[0]);
    if (num >= K) return rank_K(left, mid, tree[step].ch[0], tree[g].ch[0], K);
    K -= num;
    return rank_K(mid + 1, right, tree[step].ch[1], tree[g].ch[1], K);
  }
}
int solve(int u, int v, int K, int step, int now) {
  vector<pair<int, int> > path[2];
  path[0].clear();
  path[1].clear();
  K += ask(in_tree[u], in_tree[u], step, now);
  while (top[u] != top[v])
    if (dep[top[u]] > dep[top[v]]) {
      path[0].push_back(make_pair(top[u], u));
      u = fa[top[u]];
    } else {
      path[1].push_back(make_pair(top[v], v));
      v = fa[top[v]];
    }
  if (dep[u] >= dep[v])
    path[0].push_back(make_pair(v, u));
  else
    path[1].push_back(make_pair(u, v));
  for (int i = 0; i < path[0].size(); i++) {
    int x = in_tree[path[0][i].first], y = in_tree[path[0][i].second];
    int num = ask(x, y, step, now);
    if (num < K)
      K -= num;
    else
      return id[rank_K(x, y, step, now, num - K + 1)];
  }
  for (int i = path[1].size() - 1; i >= 0; i--) {
    int x = in_tree[path[1][i].first], y = in_tree[path[1][i].second];
    int num = ask(x, y, step, now);
    if (num < K)
      K -= num;
    else {
      return id[rank_K(x, y, step, now, K)];
    }
  }
  return -1;
}
int main() {
  int x, u, v, K, y, kind;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    link(x, i);
  }
  dfs1(mat[0]->to, 1);
  dfs2(mat[0]->to, mat[0]->to);
  ncnt = 1;
  build(1, n, 1);
  root[0] = 1;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &kind);
    if (kind == 1) {
      scanf("%d", &x);
      root[i] = ++ncnt;
      updata(x, root[i], root[i - 1]);
    } else {
      root[i] = root[i - 1];
      scanf("%d%d%d%d", &u, &v, &K, &y);
      int ans = solve(u, v, K, root[y], root[i]);
      printf("%d\n", ans == v ? -1 : ans);
    }
  }
  return 0;
}
