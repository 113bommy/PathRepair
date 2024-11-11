#include <bits/stdc++.h>
using namespace std;
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
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) {
  return !lhs ? rhs : gcd(rhs % lhs, lhs);
}
template <typename num_t>
num_t pw(num_t n, num_t k, num_t mod) {
  num_t res = 1;
  for (; k; k >>= 1) {
    if (k & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
  }
  return res;
}
const int inf = 1e9 + 7;
const long long ll_inf = 1ll * inf * inf;
const int max_n = 200000 + 7;
const int mod = inf;
struct DisjoinSet {
  vector<int> r;
  int n, group_count;
  void init(int n_) {
    n = n_;
    r.resize(n + 1);
    fill(r.begin(), r.end(), -1);
    group_count = n;
  }
  int get_root(int u) { return r[u] < 0 ? u : r[u] = get_root(r[u]); }
  bool is_root(int u) { return u == get_root(u); }
  bool join(int u, int v) {
    u = get_root(u);
    v = get_root(v);
    if (u == v) return false;
    if (r[u] > r[v]) swap(u, v);
    r[u] += r[v];
    r[v] = u;
    --group_count;
    return true;
  }
  int size(int u) { return -r[get_root(u)]; }
  bool connected(int u, int v) { return get_root(u) == get_root(v); }
} dsu;
bitset<max_n> row_mask, col_mask;
int n, m, q;
vector<pair<int, int>> row[max_n], col[max_n];
void solve() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) row_mask[i] = true;
  for (int j = 0; j < m; ++j) col_mask[j] = true;
  dsu.init(q);
  for (int i = (0), _b = (q); i < _b; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    col_mask.reset(v);
    row_mask.reset(u);
    row[u].push_back({v, i});
    col[v].push_back({u, i});
  }
  if (n == 1 || m == 1) {
    cout << n * m - q << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < row[i].size(); ++j) {
      dsu.join(row[i][j].second, row[i][j - 1].second);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < col[i].size(); ++j) {
      dsu.join(col[i][j].second, col[i][j - 1].second);
    }
  }
  cout << dsu.group_count + row_mask.count() + col_mask.count() - 1 << '\n';
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
