#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void dfs(pair<int, int> t, vector<vector<int>> &g, vector<vector<bool>> &used) {
  used[t.first][t.second] = 1;
  for (int i = 0; i < 4; ++i) {
    pair<int, int> to = t;
    to.first += dx[i];
    to.second += dy[i];
    if (to.first < 0 || to.first >= g.size() || to.second < 0 ||
        to.second >= g[0].size() || g[to.first][to.second]) {
      continue;
    }
    if (!used[to.first][to.second]) {
      dfs(to, g, used);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, v;
  cin >> n >> m >> v;
  if ((n - 2) * (n - 1) / 2 + 1 < m || m < n - 1) {
    cout << -1;
    return 0;
  }
  vector<bool> used(n, false);
  if (v != n) {
    cout << v << " " << v + 1 << endl;
    used[v + 2] = true;
  } else {
    cout << v << " " << v - 1 << endl;
    used[v - 2] = true;
  }
  int k = 1;
  used[v - 1] = true;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      cout << v << " " << i + 1 << endl;
      k++;
    }
  }
  for (int i = 0; i < n && k < m; ++i) {
    if (used[i]) {
      continue;
    }
    used[i] = true;
    for (int j = i + 1; j < n && k < m; ++j) {
      if (used[j]) {
        continue;
      }
      cout << i + 1 << " " << j + 1 << endl;
      k++;
    }
  }
  return 0;
}
