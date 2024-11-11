#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long int infP = 1e18;
long long int mnd = 1e9;
vector<pair<long long int, long long int> > a[N];
map<long long int, long long int> bak;
void dfs(long long int u) {
  for (auto v : a[u]) {
    if (bak[v.first] == 0) mnd = min(mnd, v.second);
  }
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  for (long long int i = 1; i <= m; i++) {
    long long int u, v, c;
    cin >> u >> v >> c;
    a[u].push_back({v, c});
    a[v].push_back({u, c});
  }
  vector<long long int> v(k);
  for (auto &x : v) cin >> x, bak[x]++;
  for (auto x : v) dfs(x);
  if (mnd == 1e9)
    cout << -1;
  else
    cout << mnd;
}
void debug(long long int tt) {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
