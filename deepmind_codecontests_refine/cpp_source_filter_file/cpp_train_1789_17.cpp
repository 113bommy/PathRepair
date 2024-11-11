#include <bits/stdc++.h>
using namespace std;
mt19937 rng(static_cast<unsigned int>(
    chrono::steady_clock::now().time_since_epoch().count()));
template <typename num_t>
inline void add_mod(num_t& a, const long long& b, const int& m) {
  a = (a + b) % m;
  if (a >= m) a -= m;
  if (a < 0) a += m;
}
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) {
  return a < b ? a = b, true : false;
}
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) {
  return a > b ? a = b, true : false;
}
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) {
  return !lhs ? rhs : gcd(rhs % lhs, lhs);
}
template <typename num_t>
num_t pw(num_t n, num_t k, const num_t& mod) {
  if (k == -1) k = mod - 2;
  num_t res = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
  }
  return res % mod;
}
const int inf = 1e9 + 7;
const int mod = 998244353;
const long long ll_inf = 9ll * inf * inf + 7;
const int base = 64;
const int maxn = 1007;
vector<int> adj[maxn];
int f[maxn];
int g[maxn];
int n;
void dfs(int u, int r) {
  f[u] = 1;
  for (int v : adj[u])
    if (v != r) {
      dfs(v, u);
      f[u] += f[v];
    }
}
void print_res(int u, int r, vector<int>& temp) {
  g[u] = temp.back();
  temp.pop_back();
  cout << r + 1 << ' ' << u + 1 << ' ' << g[u] - g[r] << '\n';
  for (int v : adj[u])
    if (v != r) {
      print_res(v, u, temp);
    }
}
void solve() {
  cin >> n;
  if (n == 1) return;
  if (n == 2) {
    cout << "1 2 1";
    return;
  }
  for (int i = (1), _b = (n); i < _b; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  dfs(0, -1);
  int pre_root = -1;
  int root = 0;
  while (f[root] > n / 2) {
    int nxt = -1;
    for (int v : adj[root])
      if (v != pre_root)
        if ((nxt == -1 || f[v] > f[nxt]) && n - f[v] <= n / 2) nxt = v;
    if (nxt == -1) break;
    pre_root = root;
    root = nxt;
  }
  multimap<int, vector<int>> vertexes;
  for (int v : adj[root]) {
    dfs(v, root);
    vertexes.insert({f[v], {v}});
  }
  while (vertexes.size() > 2) {
    pair<int, vector<int>> p1 = *vertexes.begin();
    vertexes.erase(vertexes.begin());
    pair<int, vector<int>> p2 = *vertexes.begin();
    vertexes.erase(vertexes.begin());
    int sum = p1.first + p2.first;
    vector<int> temp(p1.second);
    temp.insert(temp.end(), p2.second.begin(), p2.second.end());
    vertexes.insert({sum, temp});
  }
  cerr << "vertexes.size()"
       << ": " << (vertexes.size()) << '\n';
  ;
  pair<int, vector<int>> p1 = *vertexes.begin();
  vertexes.erase(vertexes.begin());
  pair<int, vector<int>> p2 = *vertexes.begin();
  vertexes.erase(vertexes.begin());
  cerr << "p1.first"
       << ": " << (p1.first) << ", "
       << "p2.first"
       << ": " << (p2.first) << '\n';
  ;
  vector<int> values(p1.first);
  iota(values.begin(), values.end(), 1);
  reverse(values.begin(), values.end());
  for (int u : p1.second) print_res(u, root, values);
  for (int i = 0; i < p2.first; ++i) values.push_back(p1.first * (i + 1) + 1);
  reverse(values.begin(), values.end());
  for (int u : p2.second) print_res(u, root, values);
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
