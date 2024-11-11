#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int a[n][n];
  bool cig[n][n], yes = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        cig[i][j] = true;
      } else {
        cig[i][j] = false;
      }
    }
  }
  for (int i1 = 0; i1 < n; ++i1) {
    for (int j1 = 0; j1 < n; ++j1) {
      for (int i2 = 0; i2 < n; ++i2) {
        if (i1 == i2) continue;
        for (int j2 = 0; j2 < n; ++j2) {
          if (j1 == j2) continue;
          int summ = a[i1][j1] + a[i2][j2];
          if (a[i1][j2] == summ) {
            cig[i1][j2] = true;
          }
          if (a[i2][j1] == summ) {
            cig[i2][j1] = true;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      yes &= cig[i][j];
    }
  }
  if (yes) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;
  return 0;
}
