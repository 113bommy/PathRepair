#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, i, j, t;
  cin >> n >> m;
  int ans = 4;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      cin >> t;
      if (t == 1) {
        if (i == 0 && (j == 0 || j == m - 1)) {
          ans = 1;
        } else if (i == n - 1 && (j == 0 || j == m - 1)) {
          ans = 1;
        } else if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
          ans = 2;
        }
      }
    }
  }
  cout << ans << endl;
}
