#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[4][100 + 5];
  int n, i, j, k;
  while (cin >> n) {
    if (n % 2 == 1) {
      a[0][n - 1] = a[1][n - 1] = 'z';
      a[3][0] = a[2][0] = 'y';
      for (i = 0; i < n - 1; i += 4) {
        a[0][i] = a[0][i + 1] = 'a';
        a[1][i] = a[1][i + 1] = 'b';
      }
      for (i = 2; i < n - 1; i += 4) {
        a[0][i] = a[0][i + 1] = 'b';
        a[1][i] = a[1][i + 1] = 'a';
      }
      for (i = 1; i < n - 1; i += 4) {
        a[2][i] = a[2][i + 1] = 'c';
        a[3][i] = a[3][i + 1] = 'd';
      }
      for (i = 3; i < n - 1; i += 4) {
        a[2][i] = a[2][i + 1] = 'd';
        a[3][i] = a[3][i + 1] = 'c';
      }
    } else {
      a[1][0] = a[2][0] = 'y';
      a[1][n - 1] = a[2][n - 1] = 'z';
      for (i = 0; i < n - 1; i += 4) {
        a[0][i] = a[0][i + 1] = 'a';
        a[3][i] = a[3][i + 1] = 'a';
      }
      for (i = 2; i < n - 1; i += 4) {
        a[0][i] = a[0][i + 1] = 'b';
        a[3][i] = a[3][i + 1] = 'b';
      }
      for (i = 1; i < n - 1; i += 4) {
        a[2][i] = a[2][i + 1] = 'c';
        a[1][i] = a[1][i + 1] = 'd';
      }
      for (i = 3; i < n - 1; i += 4) {
        a[2][i] = a[2][i + 1] = 'd';
        a[1][i] = a[1][i + 1] = 'c';
      }
    }
    for (i = 0; i < 4; i++) {
      for (j = 0; j < n; j++) cout << a[i][j];
      cout << endl;
    }
  }
}
