#include <bits/stdc++.h>
using namespace std;
int main() {
  int mat[20][20], sum[40];
  for (int i = 0; i < 3; i++) {
    sum[i] = 0;
    for (int j = 0; j < 3; j++) {
      cin >> mat[i][j];
      sum[i] += mat[i][j];
    }
  }
  mat[0][0] = (sum[1] + sum[2] - sum[0]) / 2;
  mat[1][1] = (sum[0] + sum[2] - sum[1]) / 2;
  mat[2][2] = (sum[0] + sum[1] - sum[2]) / 2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
