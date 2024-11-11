#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m], b[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> b[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = min(a[i][j], b[i][j]);
      int y = max(a[i][j], b[i][j]);
      a[i][j] = x;
      b[i][j] = y;
    }
  }
  bool check = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] >= a[i][j + 1] || b[i][j] >= b[i][j + 1]) {
        cout << "Impossible\n";
        return 0;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (a[i][j] >= a[i + 1][j] || b[i][j] >= b[i + 1][j]) {
        cout << "Impossible\n";
        return 0;
      }
    }
  }
  cout << "Possible\n";
  return 0;
}
