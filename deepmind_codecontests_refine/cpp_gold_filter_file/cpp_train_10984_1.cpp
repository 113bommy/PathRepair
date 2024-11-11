#include <bits/stdc++.h>
using namespace std;
class tree {
  int ct;

 public:
  int nn, root;
  vector<int> parent;
  vector<int> depth;
  vector<int> sz;
  vector<vector<int>> adj;
  vector<vector<int>> sons;
  vector<int> in, out;
  vector<int> pos;
  vector<vector<int>> pred;
  int MAXLEVEL;
  tree(int n) {
    nn = n;
    parent.assign(n, -1);
    adj.clear();
    adj.resize(n);
    depth.assign(n, -1);
    sz.assign(n, 0);
    sons.clear();
    sons.resize(n);
  }
  void add_path(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  void add_directed_path(int a, int b) { adj[a].push_back(b); }
  void dfs_set_root(int id, bool cartesian_decomposition = false) {
    if (cartesian_decomposition) {
      in[id] = ct;
      pos[ct] = id;
      ct++;
    }
    sz[id]++;
    for (auto p : adj[id]) {
      if (parent[p] == -1) {
        parent[p] = id;
        depth[p] = depth[id] + 1;
        dfs_set_root(p, cartesian_decomposition);
        sz[id] += sz[p];
        sons[id].push_back(p);
      }
    }
    if (cartesian_decomposition) out[id] = ct - 1;
  }
  void set_root(int id, bool cartesian_decomposition = false) {
    if (cartesian_decomposition) {
      in.resize(nn);
      out.resize(nn);
      pos.resize(nn);
      ct = 0;
    }
    parent[id] = 0;
    depth[id] = 0;
    dfs_set_root(id, cartesian_decomposition);
  }
  void prep_LCA() {
    MAXLEVEL = 1;
    while ((1 << MAXLEVEL) < nn) MAXLEVEL++;
    MAXLEVEL++;
    pred.assign(MAXLEVEL, vector<int>(nn, 0));
    pred[0] = parent;
    int i, j, k;
    for (i = 1; i < MAXLEVEL; i++) {
      for (j = 0; j < nn; j++) {
        if (pred[i - 1][j] != -1) pred[i][j] = pred[i - 1][pred[i - 1][j]];
      }
    }
  }
  int LCA(int a, int b) {
    int da = depth[a], db = depth[b];
    if (da > db) {
      swap(da, db);
      swap(a, b);
    }
    int i, j, k;
    for (i = MAXLEVEL - 1; i >= 0; i--) {
      if (db - (1 << i) >= da) {
        db -= (1 << i);
        b = pred[i][b];
      }
    }
    if (a == b) return a;
    for (i = MAXLEVEL - 1; i >= 0; i--) {
      if (pred[i][a] != pred[i][b]) {
        a = pred[i][a];
        b = pred[i][b];
      }
    }
    return parent[a];
  }
  int get_distance(int a, int b) {
    int c = LCA(a, b);
    int ans = depth[a] + depth[b] - 2 * depth[c];
    return ans;
  }
};
struct lst_node {
  long long val;
  long long offset;
  bool current;
};
class lazy_segment_tree {
 public:
  long long size;
  vector<lst_node> node_list;
  lazy_segment_tree() {}
  void initialize_empty(long long n) {
    size = n;
    lst_node lsd;
    lsd.val = 0;
    lsd.offset = 0;
    lsd.current = true;
    node_list.assign(size * 4 + 100, lsd);
  }
  long long build_tree(long long l, long long r, long long p,
                       vector<long long>& a) {
    if (l == r) {
      node_list[p].val = a[l];
      node_list[p].offset = a[l];
      node_list[p].current = true;
      return p;
    } else {
      long long m = (l + r) >> 1;
      build_tree(l, m, p * 2, a);
      build_tree(m + 1, r, p * 2 + 1, a);
      node_list[p].val = node_list[p * 2].val | node_list[p * 2 + 1].val;
      node_list[p].offset = 0;
      node_list[p].current = false;
      return p;
    }
  }
  void initialize(vector<long long>& a) {
    size = a.size();
    node_list.assign(size * 4 + 100, {0, 0});
    build_tree(0, size - 1, 1, a);
  }
  long long update(long long pos, long long key) {
    long long ans = update_range_full(1, 0, size - 1, pos, pos, key);
    return ans;
  }
  long long update_range(long long l, long long r, long long off) {
    long long ans = update_range_full(1, 0, size - 1, l, r, off);
    return ans;
  }
  long long update_range_full(long long p, long long left, long long right,
                              long long l, long long r, long long off) {
    if (left > right) return p;
    if ((left >= l) && (right <= r)) {
      if (left == right) {
        node_list[p].val = off;
        node_list[p].current = true;
        node_list[p].offset = off;
      } else {
        node_list[p].offset = off;
        node_list[p].current = true;
        node_list[p].val = off;
      }
      return p;
    } else {
      long long m = (left + right) >> 1;
      long long a, b;
      if (node_list[p].current) {
        a = update_range_full(p * 2, left, m, left, m, node_list[p].offset);
        a = update_range_full(p * 2 + 1, m + 1, right, m + 1, right,
                              node_list[p].offset);
      }
      if (m >= l) {
        a = update_range_full(p * 2, left, m, l, r, off);
      }
      if (m + 1 <= r) {
        b = update_range_full(p * 2 + 1, m + 1, right, l, r, off);
      }
      a = p * 2;
      b = p * 2 + 1;
      node_list[p].val = node_list[a].val | node_list[b].val;
      node_list[p].current = false;
      return p;
    }
  }
  long long query(long long l, long long r) {
    if (l > r) {
      return 0;
    }
    return query_full(1, 0, size - 1, l, r);
  }
  inline long long query_full(long long p, long long left, long long right,
                              long long l, long long r) {
    if (right < left) return 0;
    if ((left >= l) && (right <= r)) return node_list[p].val;
    if (node_list[p].current) return node_list[p].offset;
    long long m = (left + right) >> 1, ans = 0;
    if (m >= l) {
      ans |= query_full(p * 2, left, m, l, r);
    }
    if (m + 1 <= r) {
      ans |= query_full(p * 2 + 1, m + 1, right, l, r);
    }
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, i, j, k, a, b, ans, id, sq, q, x, cc;
  cin >> n >> m;
  vector<long long> c(n + 1), cv;
  c[0] = 0;
  for (i = 1; i <= n; i++) {
    cin >> x;
    c[i] = 1LL << x;
  }
  tree tr(n + 1);
  for (i = 0; i < n - 1; i++) {
    cin >> a >> b;
    tr.add_path(a, b);
  }
  tr.set_root(1, true);
  tr.prep_LCA();
  cv.resize(n);
  for (i = 0; i < n; i++) {
    cv[i] = c[tr.pos[i]];
  }
  lazy_segment_tree lst;
  lst.initialize(cv);
  while (m--) {
    cin >> id;
    if (id == 1) {
      cin >> x >> cc;
      cc = 1LL << cc;
      lst.update_range(tr.in[x], tr.out[x], cc);
    } else {
      cin >> x;
      long long v = lst.query(tr.in[x], tr.out[x]);
      ans = 0;
      for (i = 0; i < 62; i++) {
        if ((1LL << i) & v) ans++;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
