#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
const long long inf = 1e18;
long long i, j, k, n, m, x, y, ma = -inf, mi = inf, qq = 1, w, fr, to, t;
char ch;
vector<vector<long long> > g, rg;
void solve() {
  cin >> n >> m;
  g.assign(n, vector<long long>(0));
  rg.assign(n, vector<long long>(0));
  for (i = 0; i < m; i++) {
    cin >> fr >> to;
    fr--;
    to--;
    g[fr].push_back(to);
    rg[to].push_back(fr);
  }
  set<long long> v1, v2, v0;
  v0.insert(0);
  for (i = 1; i < n; i++) {
    bool f0 = false, f1 = false, f2 = false;
    for (auto v : rg[i]) {
      if (v0.count(v)) f0 = true;
      if (v1.count(v)) f1 = true;
      if (v2.count(v)) f2 = true;
    }
    if (f2 && !f0 && !f1)
      v0.insert(i);
    else if (f0 && !f1)
      v1.insert(i);
    else if (f1)
      v2.insert(i);
  }
  cout << v2.size() << '\n';
  for (auto v : v2) cout << v + 1 << ' ';
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> qq;
  while (qq--) {
    solve();
  }
}
