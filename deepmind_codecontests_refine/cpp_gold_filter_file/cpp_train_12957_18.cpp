#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e17;
const int mod = 1e9 + 7;
int d, n, a[2000 + 100], ans = 0;
bool mark[2000 + 100][2000 + 100];
vector<int> g[2000 + 100];
int dfs(int v, int mini, int maxi, int par) {
  if (mark[v][maxi]) return 0;
  long long t = 1;
  for (int i : g[v]) {
    if (i == par) continue;
    if (a[i] < mini || a[i] > maxi) continue;
    t *= (dfs(i, mini, maxi, v) + 1);
    t %= mod;
  }
  return t;
}
int main() {
  cin >> d >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int t, k;
    cin >> t >> k;
    g[k].push_back(t), g[t].push_back(k);
  }
  for (int i = 1; i <= n; i++) {
    ans += max(dfs(i, a[i], a[i] + d, -1), -1);
    ans %= mod;
    mark[i][a[i] + d] = true;
  }
  cout << ans << '\n';
}
