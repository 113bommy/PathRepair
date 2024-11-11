#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const long long LL_INF = 1ll * INF * INF;
const int MAX_N = 50000 + 7;
const int mod = 998244353;
template <typename num_t>
inline void addmod(num_t& a, const long long& b, const int& m) {
  a = (a + b) % m;
  if (a < 0) a += m;
}
template <typename num_t>
inline void update_max(num_t& a, const num_t& b) {
  a = max(a, b);
}
template <typename num_t>
inline void update_min(num_t& a, const num_t& b) {
  a = min(a, b);
}
const int M = 16;
const int REV = 8;
const int MAGIC = 1 << REV;
struct Node {
  int left_index, right_index;
  int lhs_child, rhs_child;
  int mid_index = 0;
  void init(int left_index_, int right_index_, int lhs_child_, int rhs_child_) {
    left_index = left_index_;
    right_index = right_index_;
    lhs_child = lhs_child_;
    rhs_child = rhs_child_;
    mid_index = (left_index + right_index) >> 1;
  }
};
vector<Node> tree;
void build_node(Node& root, int left_index, int right_index) {
  if (left_index == right_index) {
    root.init(left_index, right_index, -1, -1);
    return;
  }
  int mid = (left_index + right_index) / 2;
  static int cnt = 1;
  int lhs = cnt++, rhs = cnt++;
  build_node(tree[lhs], left_index, mid);
  build_node(tree[rhs], mid + 1, right_index);
  root.init(left_index, right_index, lhs, rhs);
}
struct Trie {
  int max_value[2 * MAGIC];
  Trie() { fill_n(max_value, 2 * MAGIC, -INF); }
  void update(int i, int pos, int val) {
    while (tree[i].left_index < tree[i].right_index) {
      update_max(max_value[i], val);
      if (pos <= tree[i].mid_index)
        i = tree[i].lhs_child;
      else
        i = tree[i].rhs_child;
    }
    update_max(max_value[i], val);
  }
  int pre_calc[MAGIC];
};
void add_number(Trie& root, int a) {
  root.update(0, a >> REV, a & (MAGIC - 1));
}
int get_max(const Trie& root, const bitset<M>& a) {
  int root_index = 0;
  int res = 0;
  for (int j = REV - 1; j >= 0; --j) {
    bool c = a[j];
    int side[2] = {tree[root_index].lhs_child, tree[root_index].rhs_child};
    if (root.max_value[side[c ^ 1]] >= 0) {
      res |= 1 << j;
      root_index = side[c ^ 1];
    } else {
      if (root.max_value[side[c]] < 0) return -INF;
      root_index = side[c];
    }
  }
  return (res << REV) + root.max_value[root_index];
}
int n, q;
vector<int> adj[MAX_N];
int a[MAX_N];
int depth[MAX_N];
int parent[MAX_N];
Trie trie[MAX_N];
int nxt[MAX_N];
void dfs(int u, int r) {
  parent[u] = r;
  for (int v : adj[u])
    if (v != r) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
}
void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  tree.resize(MAGIC * 2);
  build_node(tree[0], 0, MAGIC - 1);
  for (int v = 0; v < n; ++v)
    if (depth[v] + 1 >= MAGIC) {
      int u = v;
      for (int t = 0; t < MAGIC; ++t) {
        add_number(trie[v], a[u] ^ (depth[v] - depth[u]));
        u = parent[u];
      }
      for (int t = 0; t < MAGIC; ++t) {
        trie[v].pre_calc[t] = get_max(trie[v], t);
      }
      nxt[v] = u;
    }
  int full = (1 << M) - 1;
  while (q-- > 0) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    int temp = v;
    int ans = 0;
    while (temp != -1 && depth[temp] - depth[u] + 1 >= MAGIC && ans < full) {
      ans = max(ans, trie[temp].pre_calc[(depth[v] - depth[temp]) >> REV]);
      temp = nxt[temp];
    }
    while (temp != -1 && temp != parent[u] && ans < full) {
      ans = max(ans, a[temp] ^ (depth[v] - depth[temp]));
      temp = parent[temp];
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
