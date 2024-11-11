#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int x, y;
  vector<vector<pair<int, int>>> e(n);
  vector<int> res(n - 1);
  function<void(int, int, int)> dfs;
  dfs = [&](int x, int p, int c) -> void {
    set<int> used;
    used.insert(c);
    int nc = 1;
    for (auto& to : e[x]) {
      if (to.first == p) continue;
      while (used.count(nc)) nc++;
      res[to.second] = nc;
      dfs(to.first, x, nc);
      nc++;
    }
  };
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    x--;
    y--;
    e[x].emplace_back(y, i);
    e[y].emplace_back(x, i);
  }
  dfs(0, -1, 0);
  int mc = 0;
  cout << *max_element(res.begin(), res.end()) << '\n';
  for (int i = 0; i < n - 1; i++) cout << res[i] << '\n';
  return 0;
}