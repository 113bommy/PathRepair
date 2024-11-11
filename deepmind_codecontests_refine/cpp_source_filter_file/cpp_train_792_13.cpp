#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  int matrix[100][100];
  string a[100];
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) matrix[i][j] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = j; k < m; k++) {
        if (a[i][j] == a[i][k] && j != k) {
          matrix[i][j] = 1;
          matrix[i][k] = 1;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = j; k < n; k++) {
        if (a[j][i] == a[k][i] && j != k) {
          matrix[j][i] = 1;
          matrix[k][i] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) cout << a[i][j];
    }
  }
  return 0;
}
