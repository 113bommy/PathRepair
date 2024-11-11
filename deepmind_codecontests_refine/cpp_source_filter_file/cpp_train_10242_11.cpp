#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3][3], b[3][3], i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> a[i][j];
      b[i][j] = 1;
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if ((a[i][j] != 0) && (a[i][j] % 2 != 0)) {
        b[i][j] = !(b[i][j]);
        if (i + 1 <= 2) b[i + 1][j] = !(b[i + 1][j]);
        if (j + 1 <= 2) b[i][j + 1] = !(b[i][j + 1]);
        if (i - 1 >= 0) b[i - 1][j] = !(b[i - 1][j]);
        if (j - 1 >= 0) b[i][j - 1] = !(b[i][j - 1]);
      }
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
}
