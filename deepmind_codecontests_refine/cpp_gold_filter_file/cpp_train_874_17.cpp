#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int N = 1050;
long long xs[8][5], zb[N][2][3];
int ok[N][N], n, a[N], ans, o[N];
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
bool Gauss() {
  int i, j, k;
  for (i = 1; i <= 3; i++) {
    for (k = i; k <= 6; k++)
      if (xs[k][i]) break;
    if (k > 6)
      continue;
    else if (k != i)
      for (j = 1; j <= 4; j++) swap(xs[i][j], xs[k][j]);
    for (j = i + 1; j <= 6; j++) {
      if (xs[j][i]) {
        long long x = xs[i][i], y = xs[j][i], z = gcd(x, y);
        x /= z, y /= z;
        for (k = i; k <= 4; k++) xs[j][k] = x * xs[j][k] - y * xs[i][k];
      }
    }
  }
  return !xs[4][4] && !xs[5][4] && !xs[6][4];
}
void Create_Equation(int k, int ad) {
  xs[ad][1] = zb[k][1][1] - zb[k][0][1];
  xs[ad][2] = zb[k][0][0] - zb[k][1][0];
  xs[ad][3] = 0,
  xs[ad][4] = zb[k][0][0] * zb[k][1][1] - zb[k][1][0] * zb[k][0][1];
  xs[ad + 1][3] = zb[k][1][1] - zb[k][0][1];
  xs[ad + 1][2] = zb[k][0][2] - zb[k][1][2];
  xs[ad + 1][1] = 0,
          xs[ad + 1][4] = zb[k][0][2] * zb[k][1][1] - zb[k][1][2] * zb[k][0][1];
  xs[ad + 2][1] = zb[k][1][2] - zb[k][0][2];
  xs[ad + 2][3] = zb[k][0][0] - zb[k][1][0];
  xs[ad + 2][2] = 0,
          xs[ad + 2][4] = zb[k][0][0] * zb[k][1][2] - zb[k][1][0] * zb[k][0][2];
}
int main() {
  srand((size_t)(new char));
  int i, j, k, h;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld%lld%lld", &zb[i][0][0], &zb[i][0][1], &zb[i][0][2]);
    scanf("%lld%lld%lld", &zb[i][1][0], &zb[i][1][1], &zb[i][1][2]);
  }
  for (i = 1; i <= n; i++) {
    a[i] = i;
    for (j = i + 1; j <= n; j++) {
      Create_Equation(i, 1), Create_Equation(j, 4);
      ok[i][j] = ok[j][i] = Gauss();
    }
  }
  while (clock() <= 3250) {
    random_shuffle(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= o[0]; j++)
        if (!ok[a[i]][o[j]]) break;
      if (j > o[0]) o[++o[0]] = a[i];
    }
    if (o[0] > ans) ans = o[0];
    o[0] = 0;
  }
  printf("%d\n", ans);
  return 0;
}
