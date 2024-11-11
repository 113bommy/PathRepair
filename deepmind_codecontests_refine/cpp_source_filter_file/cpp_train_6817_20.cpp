#include <bits/stdc++.h>
using namespace std;
double a[103][103][103] = {0};
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  a[x][y][z] = 1.0;
  for (int i = x; i >= 0; i--) {
    for (int j = y; j >= 0; j--) {
      for (int k = z; k >= 0; k--) {
        if (!(i == x && j == y && k == z)) {
          if (i != i + j + k)
            a[i][j][k] = a[i + 1][j][k] * (i + 1) * k /
                         ((i + 1) * j + (i + 1) * k + j * k);
          if (j != i + j + k)
            a[i][j][k] = a[i][j][k] + a[i][j + 1][k] * (j + 1) * i /
                                          (i * (j + 1) + i * k + (j + 1) * k);
          if (k != i + j + k)
            a[i][j][k] = a[i][j][k] + a[i][j][k + 1] * (k + 1) * j /
                                          (i * j + i * (k + 1) + j * (k + 1));
        }
      }
    }
  }
  double ans = 0.0;
  for (int i = 1; i <= z; i++) ans += a[i][0][0];
  printf("%.12lf", ans);
  ans = 0.0;
  for (int i = 1; i <= y; i++) ans += a[0][i][0];
  printf(" %.12lf", ans);
  ans = 0.0;
  for (int i = 1; i <= z; i++) ans += a[0][0][i];
  printf(" %.12lf\n", ans);
  return 0;
}
