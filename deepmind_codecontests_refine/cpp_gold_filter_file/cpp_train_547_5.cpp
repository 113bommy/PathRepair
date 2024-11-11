#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<long> > matrix(n, vector<long>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> matrix[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i % 2 == j % 2) {
          if (matrix[i][j] % 2 == 0) {
            matrix[i][j]++;
          }
        } else {
          if (matrix[i][j] % 2 != 0) {
            matrix[i][j]++;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
