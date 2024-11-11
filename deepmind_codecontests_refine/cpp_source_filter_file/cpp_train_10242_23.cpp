#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[10][10] = {0}, i, j;
  int b[10][10];
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      b[i][j] = 1;
    }
  }
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) cin >> a[i][j];
  }
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      if (a[i][j] % 2 == 1) {
        b[i][j] = !b[i][j];
        b[i][j + 1] = !b[i][j + 1];
        b[i][j - 1] = !b[i][j - 1];
        b[i + 1][j] = !b[i + 1][j];
        b[i - 1][j] = !b[i - 1][j];
      } else {
        b[i][j] = b[i][j] % 2;
      }
    }
  }
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
}
