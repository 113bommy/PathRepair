#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<int>> g;
  int n, m, a, b;
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  int num, res = 0;
  vector<int> del;
  while (true) {
    num = 0;
    for (int i = 0; i < g.size(); ++i) {
      if (g[i].size() == 1) {
        num++;
        del.push_back(g[i][0]);
        g[i].pop_back();
      }
    }
    if (!num)
      break;
    else {
      for (int k = 0; k < del.size(); ++k) {
        for (int i = 0; i < g.size(); ++i) {
          for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] == del[k])
              g[i].erase(g[i].begin() + j, g[i].begin() + j + 1);
          }
        }
      }
      res++;
      del.clear();
    }
  }
  cout << res;
  return 0;
}
