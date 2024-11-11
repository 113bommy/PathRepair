#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e17;
const int N = 1 << 19;
struct Node {
  int l, r;
  long long val;
  long long toAdd;
  Node() : l(), r(), val(), toAdd() {}
  Node(int _l, int _r) : l(_l), r(_r), val(0), toAdd(0) {}
};
Node tree[2 * N + 5];
void build() {
  for (int i = 0; i < N; i++) tree[N + i] = Node(i, i + 1);
  for (int i = N - 1; i > 0; i--)
    tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void push(int v) {
  if (v >= N) throw;
  for (int u = 2 * v; u < 2 * v + 2; u++) {
    tree[u].val += tree[v].toAdd;
    tree[u].toAdd += tree[v].toAdd;
  }
  tree[v].toAdd = 0;
}
void update(int v) {
  if (v >= N) throw;
  tree[v].val = min(tree[2 * v].val, tree[2 * v + 1].val);
}
void addOnSegm(int v, int l, int r, long long dx) {
  if (l <= tree[v].l && tree[v].r <= r) {
    tree[v].val += dx;
    tree[v].toAdd += dx;
    return;
  }
  if (l >= tree[v].r || tree[v].l >= r) return;
  push(v);
  addOnSegm(2 * v, l, r, dx);
  addOnSegm(2 * v + 1, l, r, dx);
  update(v);
}
long long getMin(int v, int l, int r) {
  if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
  if (l >= tree[v].r || tree[v].l >= r) return INF;
  push(v);
  return min(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
}
struct Query {
  int l, r;
  int id;
  Query() : l(), r(), id() {}
  void scan(int _id) {
    id = _id;
    scanf("%d%d", &l, &r);
    l--;
  }
};
int n, q;
int t[N + 3][2];
long long ans[N + 3];
long long d[N + 3];
int T;
vector<pair<long long, int> > g[N + 3];
vector<Query> qq[N + 3];
void dfs1(int v) {
  t[v][0] = T++;
  for (pair<long long, int> e : g[v]) {
    int u = e.second;
    d[u] = d[v] + e.first;
    dfs1(u);
  }
  t[v][1] = T;
}
void dfs2(int v) {
  for (Query Q : qq[v]) ans[Q.id] = getMin(1, Q.l, Q.r);
  for (pair<long long, int> e : g[v]) {
    int u = e.second;
    long long w = e.first;
    addOnSegm(1, 0, n, w);
    addOnSegm(1, t[u][0], t[u][1], -2 * w);
    dfs2(u);
    addOnSegm(1, 0, n, -w);
    addOnSegm(1, t[u][0], t[u][1], 2 * w);
  }
}
int main() {
  build();
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    int p;
    long long w;
    scanf("%d%d", &p, &w);
    p--;
    g[p].push_back(make_pair(w, i));
  }
  dfs1(0);
  for (int v = 0; v < n; v++) {
    if (t[v][0] + 1 == t[v][1])
      addOnSegm(1, v, v + 1, d[v]);
    else
      addOnSegm(1, v, v + 1, INF);
  }
  for (int i = 0; i < q; i++) {
    int v;
    scanf("%d", &v);
    v--;
    Query Q;
    Q.scan(i);
    qq[v].push_back(Q);
  }
  dfs2(0);
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
