#include <bits/stdc++.h>
using namespace std;
const long long base = (int)(1e9 + 7);
const int N = 1e5 + 500;
int n;
long long sz[N];
vector<long long> vec;
vector<int> g[N];
long long mul(long long x, long long y) {
  x *= y;
  return x % base;
}
void dfs(int v, int pr) {
  sz[v] = 1;
  for (int u : g[v]) {
    if (u == pr) continue;
    dfs(u, v);
    sz[v] += sz[u];
    vec.push_back(sz[u] * (n - sz[u]));
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(0, -1);
  sort(vec.rbegin(), vec.rend());
  int m;
  cin >> m;
  vector<int> a(m);
  for (int &i : a) cin >> i;
  sort(a.begin(), a.end());
  --m;
  while (m > n - 2) a[m - 1] = mul(a[m - 1], a[m]), --m;
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    if (m < 0)
      ans = (ans + vec[i]) % base;
    else
      ans = (ans + mul(vec[i], a[m])) % base, --m;
  cout << ans << "\n";
  for (int i = 0; i < n; ++i) g[i].clear();
  vec.clear();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
