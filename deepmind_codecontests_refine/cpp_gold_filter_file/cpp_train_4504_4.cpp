#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;
void hi() {}
void bye() {}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    bool ch = true;
    int flag = 0;
    cin >> n >> m;
    long long a[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((j == 0 || j == m - 1) && (i == 0 || i == n - 1)) {
          if (a[i][j] > 2) {
            ch = false;
            flag = 1;
            break;
          }
        }
        if ((j == 0 && (i > 0 && i <= n - 2)) ||
            (i == 0 && (j > 0 && j <= m - 2)) ||
            (j == m - 1 && (i > 0 && i <= n - 2)) ||
            (i == n - 1 && (j > 0 && j <= m - 2))) {
          if (a[i][j] > 3) {
            ch = false;
            flag = 1;
            break;
          }
        }
        if ((j != 0 && j != m - 1) && (i != 0 && i != n - 1)) {
          if (a[i][j] > 4) {
            ch = false;
            flag = 1;
            break;
          }
        }
      }
    }
    if (flag == 1) {
      cout << "No";
    } else {
      cout << "Yes" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if ((j == 0 || j == m - 1) && (i == 0 || i == n - 1)) {
            cout << "2 ";
          }
          if ((j == 0 && (i > 0 && i <= n - 2)) ||
              (i == 0 && (j > 0 && j <= m - 2)) ||
              (j == m - 1 && (i > 0 && i <= n - 2)) ||
              (i == n - 1 && (j > 0 && j <= m - 2))) {
            cout << "3 ";
          }
          if ((j != 0 && j != m - 1) && (i != 0 && i != n - 1)) {
            cout << "4 ";
          }
          if (j == m - 1) cout << endl;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
