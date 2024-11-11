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
  for (; k > 0; k >>= 1) {
    if (k & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
  }
  return res;
}
const int inf = 1e9 + 7;
const int mod = 998244353;
const int MAX_N = 2000 + 7;
const long long ll_inf = 9ll * inf * inf;
template <typename num_t, typename merge = plus<num_t>,
          typename split = minus<num_t>>
struct FenWickTree {
  vector<num_t> tree;
  void update(int index, const num_t& value) {
    for (int t = index, max_t = (int)tree.size(); t < max_t; t += t & -t) {
      tree[t] = merge()(tree[t], value);
    }
  }
  num_t get(int index) {
    num_t res = 0;
    for (int t = index; t > 0; t -= t & -t) {
      res = merge()(res, tree[t]);
    }
    return res;
  }
  num_t get(int lhs, int rhs) { return split()(get(rhs), get(lhs - 1)); }
  void init(int n) { tree.assign(n + 1, 0); }
};
int n;
vector<vector<int>> a;
long long lt[MAX_N];
FenWickTree<int> tree;
long long C[MAX_N][MAX_N];
long long get_index(const vector<int>& p) {
  tree.init(n);
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int u = p[i];
    tree.update(u, 1);
    res += (u - tree.get(u)) * lt[n - i - 1];
  }
  return res % mod;
}
long long pre_calc[MAX_N][MAX_N];
FenWickTree<int> full;
long long get_position(const vector<int>& pre, const vector<int>& cur) {
  long long res = get_index(cur);
  vector<int> cnt(n + 1, 2);
  bitset<MAX_N> check;
  tree.init(n);
  full.init(n);
  for (int i = (1), _b = (n + 1); i < _b; ++i) {
    full.update(i, 1);
    tree.update(i, 1);
    check[i] = false;
  }
  int tol = n;
  for (int i = 0; i < n; ++i) {
    if (!check[pre[i]] && pre[i] < cur[i]) {
      addmod(res, -lt[n - i - 1], mod);
    }
    if (cnt[pre[i]] == 2) {
      full.update(pre[i], -1);
      --tol;
    }
    --cnt[pre[i]];
    int cnt_full = full.get(cur[i] - 1) -
                   (!check[pre[i]] && pre[i] < cur[i] && cnt[pre[i]] == 2);
    int cnt_not_full = tree.get(cur[i] - 1) -
                       (!check[pre[i]] && pre[i] < cur[i] && cnt[pre[i]] != 2) -
                       cnt_full;
    if (tol > 0) {
      addmod(res, -cnt_full * (lt[n - i - 1] - pre_calc[n - i - 1][tol - 1]),
             mod);
    }
    addmod(res, -cnt_not_full * (lt[n - i - 1] - pre_calc[n - i - 1][tol]),
           mod);
    if (cnt[cur[i]] == 2) {
      full.update(cur[i], -1);
      --tol;
    }
    --cnt[cur[i]];
    tree.update(cur[i], -1);
    check[cur[i]] = 1;
  }
  addmod(res, 0, mod);
  return res;
}
void solve() {
  lt[0] = 1;
  for (int i = 1; i < MAX_N; ++i) lt[i] = lt[i - 1] * i % mod;
  for (int i = 1; i < MAX_N; ++i) {
    C[i][i] = C[i][0] = 1;
    for (int j = (1), _b = (i); j < _b; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = 1; i < MAX_N; ++i) {
    pre_calc[i][0] = lt[i];
    addmod(pre_calc[i][1], lt[i] - lt[i - 1], mod);
    for (int j = 2; j <= i; ++j) {
      addmod(pre_calc[i][j], pre_calc[i][j - 1] - pre_calc[i - 1][j - 1], mod);
    }
  }
  cin >> n;
  a.resize(n);
  for (int i = (0), _b = (n); i < _b; ++i) {
    a[i].resize(n);
    for (int j = (0), _b = (n); j < _b; ++j) cin >> a[i][j];
  }
  if (n == 1) {
    cout << 0;
    return;
  }
  auto p = pre_calc[n][n];
  cerr << "p"
       << ": " << (p) << '\n';
  ;
  long long res = get_index(a[0]) * pw((int)p, n - 1, mod);
  for (int i = 1; i < n; ++i) {
    long long pos = get_position(a[i - 1], a[i]);
    long long temp = pos * pw((int)p, n - i - 1, mod);
    res += temp;
  }
  addmod(res, 0, mod);
  cout << res << '\n';
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
