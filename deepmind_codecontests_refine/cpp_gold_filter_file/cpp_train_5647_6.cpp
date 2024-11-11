#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    memset(a, 0, sizeof(a));
    if (m % 2 == 0) {
      for (int i = 0; i < m; i += 2) {
        for (int j = 0; j < n; j++) {
          a[j][i] = 1;
        }
      }
      a[n - 1][1] = 1;
    } else {
      for (int i = 0; i < m; i += 2) {
        for (int j = 0; j < n; j++) {
          a[j][i] = 1;
        }
      }
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          a[i][m - 1] = 1;
        } else {
          a[i][m - 1] = 0;
        }
      }
      if (n % 2 == 0) {
        a[n - 1][1] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1) {
          cout << "B";
        } else {
          cout << "W";
        }
      }
      cout << endl;
    }
  }
  return 0;
}
