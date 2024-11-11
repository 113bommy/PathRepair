#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)2e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = (int)1e9 + 7;
int d, n, a[2020];
vector<int> g[2020];
bool used[2020];
int first[2020];
int dfs(int v, int root) {
  int ans = 1;
  used[v] = true;
  for (__typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); it++) {
    int to = *it;
    if (used[to] || a[to] < a[root] || a[to] > a[root] + d ||
        (a[to] == a[root] && to < root))
      continue;
    ans = 1ll * ans * dfs(to, root) % mod;
  }
  return ans;
}
int main() {
  cin >> d >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(used, 0, sizeof used);
    ans += dfs(i, i);
    if (ans >= mod) ans -= mod;
  }
  cout << ans << endl;
  return 0;
}
