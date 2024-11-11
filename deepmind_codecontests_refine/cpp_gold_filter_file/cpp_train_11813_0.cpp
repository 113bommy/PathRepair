#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  int a[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) a[i][j] = 1;
  }
  int b[m][n];
  int c[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) c[i][j] = 0;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      if (b[i][j] == 0) {
        for (int k = 0; k < m; k++) a[k][j] = 0;
        for (int l = 0; l < n; l++) a[i][l] = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1) {
        for (int k = 0; k < m; k++) c[k][j] = 1;
        for (int l = 0; l < n; l++) c[i][l] = 1;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (b[i][j] != c[i][j]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
