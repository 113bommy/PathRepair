#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
vector<int> g[maxn];
int sz[maxn], heavy[maxn], par[maxn], root[maxn], pos[maxn], d[maxn];
int tick;
long long a[maxn];
vector<long long> order;
template <typename T>
struct lazysegtree {
  struct node {
    int l, r;
    T val;
    int lenght() { return r - l + 1; }
  };
  int n;
  vector<node> seg;
  vector<T> arr;
  lazysegtree(int _n, vector<T> _arr) : seg(4 * _n + 1) {
    n = _n;
    arr = _arr;
    Build(1, 0, n - 1);
  }
  void Recalculate(int ind) {
    assert(ind * 2 < (int)seg.size());
    node& leftChild = seg[ind * 2];
    assert(ind * 2 + 1 < (int)seg.size());
    node& rightChild = seg[ind * 2 + 1];
    seg[ind].val = leftChild.val + rightChild.val;
  }
  void Push(int ind) {
    assert(ind * 2 < (int)seg.size());
    node& leftChild = seg[ind * 2];
    assert(ind * 2 + 1 < (int)seg.size());
    node& rightChild = seg[ind * 2 + 1];
  }
  void Build(int ind, int l, int r) {
    seg[ind].l = l;
    seg[ind].r = r;
    if (l == r) {
      seg[ind].val = arr[l];
      return;
    }
    int mid = (l + r) / 2;
    Build(ind * 2, l, mid);
    Build(ind * 2 + 1, mid + 1, r);
    Recalculate(ind);
  }
  void Upd(int l, int r, T val) {
    assert(r < n);
    Upd(l, r, val, 0, n - 1, 1);
  }
  void Upd(int l, int r, T val, int cl, int cr, int ind) {
    if (cl > r || cr < l) return;
    if (cl >= l && cr <= r) {
      seg[ind].val = val;
      return;
    }
    Push(ind);
    int mid = (cl + cr) / 2;
    Upd(l, r, val, cl, mid, ind * 2);
    Upd(l, r, val, mid + 1, cr, ind * 2 + 1);
    Recalculate(ind);
  }
  T Get(int l, int r) {
    assert(r < n);
    return Get(l, r, 0, n - 1, 1);
  }
  T Get(int l, int r, int cl, int cr, int ind) {
    if (cl > r || cr < l) return 0;
    if (cl >= l && cr <= r) {
      return seg[ind].val;
    }
    Push(ind);
    int mid = (cl + cr) / 2;
    T L = Get(l, r, cl, mid, ind * 2);
    T R = Get(l, r, mid + 1, cr, ind * 2 + 1);
    Recalculate(ind);
    return L + R;
  }
};
long long calc(int u, int v) { return max(abs(a[u] + a[v]), abs(a[u] - a[v])); }
void dfs(int u, int dep, int p = 1) {
  sz[u] = 1;
  par[u] = p;
  d[u] = dep;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, dep + 1, u);
      sz[u] += sz[v];
      if (sz[heavy[u]] < sz[v]) heavy[u] = v;
    }
  }
  if (!heavy[u]) heavy[u] = u;
}
void dfs2(int u, int proot, int p = 1) {
  pos[u] = tick++;
  root[u] = proot;
  if (heavy[u] != u) {
    order.push_back(calc(u, heavy[u]));
    dfs2(heavy[u], proot, u);
    for (int v : g[u])
      if (v != p && v != heavy[u]) {
        order.push_back(0);
        dfs2(v, v, u);
      }
  }
}
long long query(int u, int v, lazysegtree<long long>& tree) {
  int ru = root[u];
  int rv = root[v];
  if (ru == rv) return tree.Get(min(pos[u], pos[v]), max(pos[u], pos[v]) - 1);
  if (d[ru] > d[rv]) {
    long long tq = tree.Get(pos[ru], pos[u] - 1);
    return tq + calc(par[ru], ru) + query(par[ru], v, tree);
  } else {
    long long tq = tree.Get(pos[rv], pos[v] - 1);
    return tq + calc(par[rv], rv) + query(u, par[rv], tree);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 1);
  lazysegtree<long long> tree(order.size(), order);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] = y;
      if (x != heavy[x]) {
        order[pos[x]] = calc(x, heavy[x]);
        tree.Upd(pos[x], pos[x], order[pos[x]]);
      }
      if (root[x] != x && root[x] == root[par[x]]) {
        order[pos[par[x]]] = calc(par[x], x);
        tree.Upd(pos[par[x]], pos[par[x]], order[pos[par[x]]]);
      }
    } else {
      cout << query(x, y, tree) << "\n";
    }
  }
}
