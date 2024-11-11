#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  int grid[n][m];
  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      v.push_back(grid[i][j]);
    }
  }
  int rem = grid[0][0] % d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] % d != rem) {
        cout << -1 << "\n";
        return 0;
      }
    }
  }
  sort(v.begin(), v.end());
  int need = v[(int)v.size() / 2];
  int ret = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    ret += abs((need - v[i])) / d;
  }
  cout << ret << "\n";
}
