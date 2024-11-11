#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  double mat[170][170];
  double a[170][170];
  double b[170][170];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = (mat[i][j] + mat[j][i]) / 2;
      b[i][j] = mat[i][j] - a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
