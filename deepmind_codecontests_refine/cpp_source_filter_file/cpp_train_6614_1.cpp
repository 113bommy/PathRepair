#include <bits/stdc++.h>
using namespace std;
struct mat {
  int x, y;
};
struct mat arr[10001];
int matrix[101][101];
int main() {
  int row, col, val, a, n, m, q, b;
  cin >> n >> m >> q;
  int num = 0;
  while (q--) {
    cin >> a;
    if (a == 1 || a == 2) {
      cin >> b;
      arr[num].x = a;
      arr[num].y = b;
      num++;
    } else {
      cin >> row >> col >> val;
      for (int i = num - 1; i >= 0; i--) {
        int todo = arr[i].x;
        int wat = arr[i].y;
        if (todo == 2) {
          if (wat == col) row++;
          if (row > n) row = 1;
        } else {
          if (wat == row) col++;
          if (row > m) col = 1;
        }
      }
      matrix[row][col] = val;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
