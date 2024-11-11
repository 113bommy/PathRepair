#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
const int inf = 1e9;
const long long inf2 = 1e18;
const int mod = 1e9 + 7;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const int N = 3e5 + 2;
vector<int> adj[N];
long long tree[2][2 * N];
int tin[N], tout[N], timer = 1;
long long depth[N];
void dfs(int u, int d) {
  tin[u] = timer++;
  depth[u] = d;
  for (auto v : adj[u]) {
    dfs(v, d + 1);
  }
  tout[u] = timer++;
}
long long read(int idx, int i) {
  long long sum = 0;
  while (idx > 0) {
    sum += tree[i][idx];
    sum %= mod;
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int idx, long long val, int i) {
  while (idx < 2 * N) {
    tree[i][idx] += val;
    tree[i][idx] %= mod;
    idx += (idx & -idx);
  }
}
void solve() {
  int n;
  cin >> n;
  int p;
  for (int i = 2; i < n + 1; ++i) {
    cin >> p;
    adj[p].push_back(i);
  }
  dfs(1, 0);
  int q;
  cin >> q;
  int t, v;
  long long x, k;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> v >> x >> k;
      update(tin[v], x + depth[v] * k, 0);
      update(tout[v], -1LL * (x + depth[v] * k), 0);
      update(tin[v], k, 1);
      update(tout[v], -k, 1);
    } else {
      cin >> v;
      x = read(tin[v], 0);
      x = (x + mod - (depth[v] * (read(tin[v], 1))) % mod) % mod;
      cout << x << '\n';
    }
  }
  return;
}
int main() {
  boost();
  int tc = 1;
  while (tc--) solve();
  return 0;
}
