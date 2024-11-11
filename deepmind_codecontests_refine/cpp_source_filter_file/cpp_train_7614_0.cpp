#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, h;
  cin >> n >> m >> h;
  int a[m + 1], b[n + 1], x[n + 1][m + 1];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (x[i][j] * min(a[i], b[j])) << " ";
    }
    cout << "\n";
  }
  return 0;
}
