#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
double ans, f[2][N];
int now, n, k;
int main() {
  scanf("%d%d", &n, &k);
  now = 0;
  for (int i = n - 1; i >= 0; i--) {
    now ^= 1;
    for (int j = 1; j <= 600; j++)
      f[now][j] =
          f[now ^ 1][j] * (j * 1.0 / (j + 1.0) / k + (k - 1) * 1.0 / k) +
          (j * 1.0 / 2 + j * 1.0 / (j + 1)) / k +
          1.0 / (j + 1) * f[now ^ 1][j + 1] / k;
  }
  printf("%.12lf\n", k * f[now][1]);
}
