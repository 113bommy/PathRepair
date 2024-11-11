#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, no = 0;
  cin >> n;
  char a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      if ((a[i][k + 1] == '#') &&
          (a[i + 1][k] == '#' && a[i + 1][k + 1] == '#' &&
           a[i + 1][k + 2] == '#') &&
          (a[i + 2][k + 1] == '#')) {
        a[i][k + 1] = ' ';
        a[i + 1][k] = ' ';
        a[i + 1][k + 1] = ' ';
        a[i + 1][k + 2] = ' ';
        a[i + 2][k + 1] = ' ';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (a[i][j] == '#') {
        no = 1;
        break;
      }
  }
  if (no == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
