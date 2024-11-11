#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 30;
const int MAXL = 300;
vector<int> g[MAXN];
pair<int, int> dfs(int u, int p, const int &k) {
  pair<int, int> ret;
  int mx1 = 0, mx2 = 0;
  for (int v : g[u]) {
    if (v == p) continue;
    auto tmp = dfs(v, u, k);
    ret.first += tmp.first;
    if (tmp.second >= mx1) {
      mx2 = mx1;
      mx1 = tmp.second;
    } else if (tmp.second > mx2)
      mx2 = tmp.second;
  }
  if (mx1 + mx2 + 1 >= k) {
    ret.first++;
    ret.second = 0;
  } else
    ret.second = mx1 + 1;
  return ret;
}
vector<int> ans(MAXN, -1);
inline int get(const int &k) {
  return (ans[k] == -1 ? ans[k] = dfs(1, -1, k).first : ans[k]);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= min(n, MAXL); i++) get(i);
  int prv = n + 1;
  for (int i = 0; i <= MAXL; i++) {
    int l = 0, r = min(n / max(i, 1), prv) + 1, m;
    while (l + 1 < r) {
      m = (l + r) / 2;
      if (get(m) <= i)
        r = m;
      else
        l = m;
    }
    for (int j = r; j < prv; j++) ans[j] = i;
    prv = r;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
  return 0;
}
