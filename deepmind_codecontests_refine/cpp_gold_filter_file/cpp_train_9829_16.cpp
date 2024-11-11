#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, i, j, k, l, o, p, q, r;
  cin >> n >> m;
  int a[n + 10][m + 10];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  l = 0;
  for (i = 0; i < n; i++) {
    if (i == 0 || i == n - 1) {
      for (j = 0; j < m; j++) {
        if (a[i][j] == 1) {
          l = 1;
        }
      }
    } else {
      if (a[i][0] == 1 || a[i][m - 1] == 1) {
        l = 1;
      }
    }
  }
  if (l == 1) {
    cout << "2";
    return 0;
  } else {
    cout << "4";
    return 0;
  }
}
