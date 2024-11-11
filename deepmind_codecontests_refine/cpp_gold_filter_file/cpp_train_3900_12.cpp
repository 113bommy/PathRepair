#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
int n;
long long f[2010][2010], g[2010][2010], a[2010][2010], b[2010][2010],
    x[2010][2010];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &x[i][j]);
      f[i][j] = g[i][j] = a[i][j] = b[i][j] = x[i][j];
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i && j) {
        f[i][j] += f[i - 1][j - 1];
      }
  for (int i = n - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--)
      if (i != n - 1 && j != n - 1) {
        g[i][j] += g[i + 1][j + 1];
      }
  for (int i = 0; i < n; i++)
    for (int j = n - 1; j >= 0; j--)
      if (i && j != n - 1) {
        a[i][j] += a[i - 1][j + 1];
      }
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j < n; j++)
      if (i != n - 1 && j) {
        b[i][j] += b[i + 1][j - 1];
      }
  long long Max1 = -1, Max2 = -1, ax, ay, bx, by;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      long long tmp = f[i][j] + g[i][j] + a[i][j] + b[i][j] - x[i][j] * 3;
      if ((i + j) & 1) {
        if (tmp > Max1) {
          Max1 = tmp;
          ax = i;
          ay = j;
        }
      } else {
        if (tmp > Max2) {
          Max2 = tmp;
          bx = i;
          by = j;
        }
      }
    }
  cout << Max1 + Max2 << endl;
  cout << ax + 1 << " " << ay + 1 << " " << bx + 1 << " " << by + 1 << endl;
  return 0;
}
