#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  double w[n][n], a[n][n], b[n][n];
  for (int i = 0; i < n; i++)
    for (int x = 0; x < n; cin >> w[i][x++])
      ;
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < n; x++) {
      if (x == i)
        a[i][x] = w[i][x], b[i][x] = 0.0;
      else if (w[i][x] != -1717 && w[i][x] < w[x][i]) {
        double con = (w[x][i] - w[i][x]) / 2.0;
        a[i][x] = con + w[i][x], a[x][i] = a[i][x];
        b[i][x] = -con, b[x][i] = con;
        w[i][x] = -1717, w[x][i] = -1717;
      } else if (w[i][x] != -1717 && w[i][x] >= w[x][i]) {
        double con = (w[i][x] - w[x][i]) / 2.0;
        a[i][x] = con + w[x][i], a[x][i] = a[i][x];
        b[i][x] = con, b[x][i] = -con;
        w[i][x] = -1717, w[x][i] = -1717;
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int x = 0; x < n; x++) {
      cout << fixed;
      cout << setprecision(8) << a[i][x] << " \n"[x == n - 1];
    }
  for (int i = 0; i < n; i++)
    for (int x = 0; x < n; x++) {
      cout << fixed;
      cout << setprecision(8) << b[i][x] << " \n"[x == n - 1];
    }
  return 0;
}
