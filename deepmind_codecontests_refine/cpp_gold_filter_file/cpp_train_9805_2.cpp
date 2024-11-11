#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  bool a[7][7] = {};
  cin >> n >> m;
  for (int i = 0, x, y; i < m; ++i) {
    cin >> x >> y;
    a[x - 1][y - 1] = true;
    a[y - 1][x - 1] = true;
  }
  if (n < 7) {
    cout << m;
    return 0;
  }
  int min_common = 5;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int common = 0;
      for (int k = 0; k < n; ++k) {
        if (k != i && k != j && a[k][i] && a[k][j]) {
          ++common;
        }
      }
      min_common = min(min_common, common);
    }
  }
  cout << m - min_common;
  return 0;
}
