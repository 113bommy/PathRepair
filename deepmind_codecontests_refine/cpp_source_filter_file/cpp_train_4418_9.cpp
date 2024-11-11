#include <bits/stdc++.h>
using namespace std;
int n;
int w[171][171];
double a[171][171];
double b[171][171];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> w[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    a[i][i] = w[i][i];
    b[i][i] = 0.0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + i; j < n; ++j) {
      b[i][j] = (w[i][j] - w[j][i]) / 2.0;
      b[j][i] = -b[i][j];
      a[i][j] = w[i][j] - b[i][j];
      a[j][i] = a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j) cout << ' ';
      cout << fixed << setprecision(8) << a[i][j];
    }
    cout << endl;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j) cout << ' ';
      cout << fixed << setprecision(8) << b[i][j];
    }
    cout << endl;
  }
  return 0;
}
