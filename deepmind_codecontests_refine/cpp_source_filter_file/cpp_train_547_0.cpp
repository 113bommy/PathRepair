#include <bits/stdc++.h>
using namespace std;
int matrix[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
bool isValid(int row, int col) {
  return (row >= 0 && row < n) && (col >= 0 && col < m);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        cin >> matrix[r][c];
      }
    }
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        matrix[r][c] += (r ^ c % 2) != (matrix[r][c] % 2);
      }
    }
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        cout << matrix[r][c] << " ";
      }
      cout << endl;
    }
  }
}
