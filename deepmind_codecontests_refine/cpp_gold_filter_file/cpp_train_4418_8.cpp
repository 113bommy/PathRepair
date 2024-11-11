#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  double** a = new double*[n];
  double** b = new double*[n];
  double** w = new double*[n];
  for (int i = 0; i < n; i++) {
    a[i] = new double[n];
    b[i] = new double[n];
    w[i] = new double[n];
    for (int j = 0; j < n; j++) cin >> w[i][j];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      a[j][i] = a[i][j] = (w[j][i] + w[i][j]) / 2;
      b[i][j] = w[i][j] - a[i][j];
      b[j][i] = 0 - b[i][j];
    }
  cout << fixed << setprecision(8);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
    cout << endl;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << b[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
