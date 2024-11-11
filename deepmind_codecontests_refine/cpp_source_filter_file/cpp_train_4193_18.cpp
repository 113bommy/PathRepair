#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, m, c = 0;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && a[i][j] != 'R' && j != m - 1) {
          c++;
        }
        if ((j) == (m - 1) && (a[i][j] != 'D') && (i != n - 1)) {
          c++;
        }
      }
    }
    cout << c << endl;
    t--;
  }
}
