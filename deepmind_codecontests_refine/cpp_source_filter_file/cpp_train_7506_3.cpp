#include <bits/stdc++.h>
using namespace std;
template <typename IT>
ostream &print(IT b, IT e, string sep = " ", ostream &stream = cout) {
  for (IT it = b; it != e; ++it) {
    stream << *it;
    if (it + 1 != e) stream << sep;
  }
  return stream;
}
template <typename IT>
istream &read(IT b, IT e, istream &stream = cin) {
  for (IT it = b; it != e; ++it) stream >> *it;
  return stream;
}
template <typename T>
ostream &operator<<(ostream &stream, vector<T> &t) {
  return print((t).begin(), (t).end(), " ", stream);
}
template <typename T>
ostream &operator<<(ostream &stream, vector<T> &&t) {
  return print((t).begin(), (t).end(), " ", stream);
}
template <typename T>
istream &operator>>(istream &stream, vector<T> &t) {
  return read((t).begin(), (t).end(), stream);
}
template <typename T>
void print(T x, string end = "\n") {
  cout << x << end;
}
template <typename t>
void print(vector<t> arr, string sep = " ") {
  if (arr.empty()) {
    return;
  }
  print(arr.begin(), arr.end(), sep);
  cout << '\n';
}
template <typename T>
void print(vector<vector<T> > arr) {
  for (int i = 0; i < int(arr.size()); ++i) {
    cout << "[" << arr[i] << "]";
    if (i + 1 < int(arr.size())) cout << ", ";
  }
  cout << '\n';
}
template <typename T>
T _();
const long long MOD = 998244353;
template <typename T>
vector<T> operator+(const vector<T> &lhs, const vector<T> &rhs) {
  vector<T> ans(lhs);
  assert(ans.size() == rhs.size());
  for (int i = 0; i < rhs.size(); ++i) ans[i] += rhs[i];
  return ans;
}
template <typename T>
vector<T> operator+=(vector<T> &lhs, const vector<T> &rhs) {
  return lhs = lhs + rhs;
}
template <typename T>
vector<T> operator-(const vector<T> lhs, const vector<T> rhs) {
  vector<T> ans((lhs).begin(), (lhs).end());
  assert(ans.size() == rhs.size());
  for (int i = 0; i < rhs.size(); ++i) ans[i] -= rhs[i];
  return ans;
}
template <typename T>
vector<T> operator-=(vector<T> &lhs, const vector<T> &rhs) {
  return lhs = lhs - rhs;
}
template <typename T>
vector<T> append(vector<T> &lhs, const vector<T> rhs) {
  lhs.insert(lhs.end(), (rhs).begin(), (rhs).end());
  return lhs;
}
template <typename T>
T max(const vector<T> arr) {
  assert(!arr.empty());
  T ans = arr[0];
  for (auto &cur : arr) ans = max(ans, cur);
  return ans;
}
template <typename T>
T max(const set<T> s) {
  assert(!s.empty());
  return *--s.end();
}
template <typename T, typename G>
vector<T> set_max(vector<T> &base, const vector<G> &comp) {
  assert(base.size() == comp.size());
  for (int i = 0; i < (int)comp.size(); ++i) base[i] = max(base[i], comp[i]);
  return base;
}
long long ext_euclid(long long a, long long b, long long c, long long d) {
  if (c == 0) return b;
  return ext_euclid(c, d, a % c, b - a / c * d);
}
long long mod_inverse(long long x, long long mod = MOD) {
  return (ext_euclid(mod, 0, x, 1) + mod) % mod;
}
long long ipow(long long x, long long p, long long mod = MOD) {
  if (x >= mod) x %= mod;
  if (p == 0) return 1;
  if (p == 1) return x;
  return ipow(x * x % mod, p / 2, mod) * ipow(x, p % 2, mod) % mod;
}
const int N = 5e5 + 5;
long long orphan_root[N];
vector<int> adj[N];
long long ans = 0;
long long mult;
void dfs(int u, int p) {
  orphan_root[u] = 1;
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    orphan_root[u] *= 1 - orphan_root[v] * mod_inverse(2) % MOD;
    orphan_root[u] %= MOD;
    if (orphan_root[u] < 0) orphan_root[u] += MOD;
  }
  if ((adj[u].size() - p != -1) != 0) {
    ans += (1 - orphan_root[u]) * mult;
    ans %= MOD;
  }
}
void _() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  mult = ipow(2, n - 1);
  dfs(1, -1);
  ans = (ans * 2) % MOD;
  if (ans < 0) ans += MOD;
  print(ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  _();
}
