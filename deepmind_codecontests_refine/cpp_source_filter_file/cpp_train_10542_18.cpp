#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
const double eps = 1e-6;
long long det(int ax, int ay, int bx, int by, int cx, int cy) {
  return (long long)(cy - ay) * (bx - ax) - (long long)(cx - ax) * (by - ay);
}
int n, m, x[1000], y[1000], z[1000], f[510][510];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);
  for (int k = 0; k < m; k++) {
    int ax, ay;
    scanf("%d%d", &ax, &ay);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (x[i] < x[j]) {
          if (x[i] <= ax && ax <= x[j] &&
              det(x[i], y[i], x[j], y[j], ax, ay) > 0) {
            f[i][j]++;
            f[j][i]--;
          }
        }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (i != j && j != k && i != k)
          ans += (f[i][j] + f[j][k] + f[k][i] == 0);
  printf("%d\n", ans / 6);
}
