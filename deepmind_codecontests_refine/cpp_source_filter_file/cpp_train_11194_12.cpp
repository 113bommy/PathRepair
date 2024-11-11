#include <bits/stdc++.h>
using namespace std;
void fillMatrix(int mat[][100], int n, int a, int b, int currx, int curry,
                int &lastOdd, int &lastEven) {
  int delta[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for (int i = 0; i < 4; i++) {
    int newx = currx + delta[i][0], newy = curry + delta[i][1];
    if (newx >= 0 && newx < a && newy >= 0 && newy < b &&
        mat[newx][newy] == 0) {
      if (mat[currx][curry] % 2 == 0 && lastOdd <= n) {
        mat[newx][newy] = lastOdd;
        lastOdd += 2;
      } else if (mat[currx][curry] % 2 != 0 && lastEven <= n) {
        mat[newx][newy] = lastEven;
        lastEven += 2;
      }
    } else {
      continue;
    }
  }
  return;
}
int main() {
  int n, a, b, mat[100][100] = {0};
  cin >> n >> a >> b;
  if (n > a * b) {
    cout << "-1";
    return 0;
  }
  int odd = 3, even = 2;
  mat[0][0] = 1;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < a; j++) {
      if (odd <= n || even <= n) {
        fillMatrix(mat, n, a, b, i, j, odd, even);
      }
    }
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      cout << mat[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
