#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int main() {
  cin >> n >> m;
  vector<int> g[n];
  set<int> s[n];
  vector<pair<int, int>> t;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    a--;
    t.push_back({a, i});
  }
  sort(t.begin(), t.end());
  vector<int> ans;
  bool ff = false;
  for (const auto &ti : t) {
    int ac = 0;
    while (!s[ti.second].empty() && s[ti.second].find(ac) != s[ti.second].end())
      ac++;
    if (ac != ti.first) {
      ff = true;
      break;
    }
    for (int &v : g[ti.second]) g[v].push_back(ti.first);
    ans.push_back(ti.second + 1);
  }
  if (ff) {
    cout << -1 << "\n";
    return 0;
  }
  for (const int &e : ans) cout << e << " ";
  cout << "\n";
  return 0;
}
