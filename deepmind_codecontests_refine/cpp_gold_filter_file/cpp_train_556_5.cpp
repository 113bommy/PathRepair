#include <bits/stdc++.h>
using namespace std;
int main() {
  int mat[3][3];
  int lim = 0, sum;
  for (int i = 0; i < 3; i++) {
    sum = 0;
    for (int j = 0; j < 3; j++) {
      cin >> mat[i][j];
      sum += mat[i][j];
    }
    lim = max(sum, lim);
  }
  for (int i = 1; i <= 100000; i++) {
    mat[0][0] = i;
    sum = mat[0][0] + mat[0][1] + mat[0][2];
    if ((sum - mat[1][0] - mat[1][2] <= 0) ||
        (sum - (mat[0][1] + mat[2][1]) <= 0) ||
        (mat[0][1] + mat[2][1] != mat[1][0] + mat[1][2]))
      continue;
    mat[1][1] = sum - (mat[1][0] + mat[1][2]);
    if ((sum - mat[2][0] - mat[2][1] <= 0) ||
        (sum - (mat[0][2] + mat[1][2]) <= 0) ||
        (mat[2][0] + mat[2][1] != mat[0][2] + mat[1][2]))
      continue;
    mat[2][2] = sum - (mat[2][0] + mat[2][1]);
    if (mat[0][0] + mat[1][1] + mat[2][2] != sum ||
        mat[1][1] + mat[0][2] + mat[2][0] != sum)
      continue;
    break;
  }
  for (int i = 0; i < 3; i++) {
    cout << mat[i][0];
    for (int j = 1; j < 3; j++) {
      cout << " " << mat[i][j];
    }
    cout << endl;
  }
  return 0;
}
