#include <bits/stdc++.h>
using namespace std;
int a[2002];
vector<int> g[2002];
long long mod = 1000000007;
long long dfs(int cur, int par, int root, int d) {
  long long ret = 1;
  for (int e : g[cur]) {
    if (e != par && (a[e] < a[root] || (a[e] == a[root] && e < root)) &&
        a[e] >= a[root] - d) {
      ret = ret * (dfs(e, cur, root, d) + 1) % mod;
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  int d, n;
  cin >> d >> n;
  for (int _n(n), i(0); i < _n; i++) cin >> a[i];
  for (int _n(n - 1), i(0); i < _n; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  long long ans = 0;
  for (int _n(n), i(0); i < _n; i++) ans += dfs(i, -1, i, d);
  cout << ans % mod << endl;
  return 0;
}
