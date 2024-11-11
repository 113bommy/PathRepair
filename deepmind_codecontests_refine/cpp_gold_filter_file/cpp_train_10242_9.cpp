#include <bits/stdc++.h>
using namespace std;
int main() {
  bool mat[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  int tog[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> tog[i][j];
      tog[i][j] = tog[i][j] % 2;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tog[i][j] == 1) {
        mat[i][j] = !mat[i][j];
        if (i - 1 >= 0) mat[i - 1][j] = !mat[i - 1][j];
        if (i + 1 < 3) mat[i + 1][j] = !mat[i + 1][j];
        if (j - 1 >= 0) mat[i][j - 1] = !mat[i][j - 1];
        if (j + 1 < 3) mat[i][j + 1] = !mat[i][j + 1];
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << mat[i][j];
    }
    cout << endl;
  }
  return 0;
}
