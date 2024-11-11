#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const int maxn = 3e5 + 3;
void pvec(vector<long long int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}
long long int gcd(long long int x, long long int y) {
  if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}
long long int binpow(long long int a, long long int b) {
  if (b == 0) {
    return 1;
  }
  long long int res = 1;
  long long int tmp = binpow(a, b / 2);
  res = (tmp * tmp) % mod;
  if (b % 2 == 1) {
    res = (res * a) % mod;
  }
  return res;
}
vector<vector<int> > adj;
vector<int> tim(maxn, 0), low(maxn, 0), mx(maxn, 0);
int dfs_no = 0, ans = 0;
int n, m;
void dfs(int u, int par = -1) {
  tim[u] = low[u] = ++dfs_no;
  for (int v : adj[u]) {
    if (!tim[v]) {
      dfs(v, u);
      ans = max(ans, mx[u] + mx[v] + (tim[u] < low[v]));
      mx[u] = max(mx[u], mx[v] + (tim[u] < low[v]));
      low[u] = min(low[u], low[v]);
    } else if (v != par) {
      low[u] = min(low[u], tim[v]);
    }
  }
}
void solve() {
  cin >> n >> m;
  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
