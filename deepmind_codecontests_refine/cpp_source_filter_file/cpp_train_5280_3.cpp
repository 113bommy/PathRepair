#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, u, v;
vector<int> g[100005 + 2];
int used[100005 + 2], coun[100005 + 2];
int dfs(int v) {
  used[v] = 1, coun[v] = 1;
  for (int x : g[v]) {
    if (used[x]) continue;
    coun[v] += dfs(x);
  }
  return coun[v];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (!(n & 1)) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  int res = 0;
  for (int i = 1; i <= n; ++i)
    if (!(coun[i] & 1)) {
      res += 1;
    }
  cout << res - 1 << endl;
}
