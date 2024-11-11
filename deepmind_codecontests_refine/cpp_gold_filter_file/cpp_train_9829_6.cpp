#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = 10, i, j;
  cin >> n >> m;
  int a[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
          ans = 2;
        else
          ans = min(4, ans);
      }
    }
  }
  cout << ans;
}
