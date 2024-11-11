#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[j][m - 1 - i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m / 2; j++) {
      swap(a[i][j], a[i][m - 1 - j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 2; k++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << a[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
