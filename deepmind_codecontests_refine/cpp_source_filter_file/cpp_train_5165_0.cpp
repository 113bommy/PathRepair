#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int d[N];
vector<vector<pair<int, int> > > g(N);
bool u[N];
vector<int> ans;
int dfs(int v, int index) {
  u[v] = 1;
  for (pair<int, int> to : g[v])
    if (!u[to.first]) d[v] ^= dfs(to.first, to.second);
  if (d[v]) ans.push_back(index);
  return d[v];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> notdef;
  int parity = 0;
  for (int i = 1; i <= n; ++i) {
    int par;
    cin >> par;
    d[i] = par;
    if (par == 1)
      parity ^= 1;
    else if (par == -1)
      notdef.push_back(i);
  }
  if (parity == 1 && notdef.size() == 0) {
    cout << -1;
    return 0;
  }
  if (parity == 1) d[notdef.back()] = 1, notdef.pop_back();
  for (int i = 0; i < notdef.size(); ++i) d[notdef[i]] = 0;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back({b, i + 1});
    g[b].push_back({});
  }
  dfs(1, -1);
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << '\n';
  return 0;
}
