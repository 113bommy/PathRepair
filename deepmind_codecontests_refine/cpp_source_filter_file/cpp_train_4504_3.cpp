#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    }
    int f = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int c = 4;
        if (i == 0) c--;
        if (i == n - 1) c--;
        if (j == 0) c--;
        if (j == n - 1) c--;
        if (mat[i][j] > c) {
          f = 0;
          break;
        }
        mat[i][j] = c;
      }
      if (f == 0) break;
    }
    if (f == 0)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << mat[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
}
