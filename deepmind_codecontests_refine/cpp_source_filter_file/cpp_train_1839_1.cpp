#include <bits/stdc++.h>
using namespace std;
vector<map<int, int>> d;
int calc(int x, int w) {
  auto it = d[x].lower_bound(w);
  if (it == d[x].begin()) return 1;
  it--;
  return (it->second + 1);
}
signed main() {
  int n, m;
  cin >> n >> m;
  d = vector<map<int, int>>(n + 1);
  int sol = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    int res = calc(u, w);
    if (calc(v, w + 1) > res) continue;
    d[v][w] = max(d[v][w], res);
    auto it = d[v].upper_bound(w);
    while (it == d[v].end() && it->second > res) {
      it = d[v].erase(it);
    }
    sol = max(sol, res);
  }
  cout << sol << '\n';
}
