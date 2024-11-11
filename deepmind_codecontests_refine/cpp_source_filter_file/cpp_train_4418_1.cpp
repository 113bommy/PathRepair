#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int w[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> w[i][j];
    }
  }
  double x[n][n], y[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      x[i][j] = (w[i][j] + w[j][i]) / 2.0;
      y[j][i] = (w[i][j] - w[j][i]) / 2.0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << fixed << setprecision(8) << x[i][j] << " ";
    }
    cout << "\n";
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << fixed << setprecision(8) << y[i][j] << " ";
    }
    cout << "\n";
  }
}
