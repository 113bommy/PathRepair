#include <bits/stdc++.h>
using namespace std;
int n, k;
double f[2][810];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i * i <= n; ++i) f[0][i] = 0;
  int st = min(max(800.0, sqrt(n)), 1.0 * n);
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    c ^= 1;
    for (int j = 1; j <= st; ++j) {
      f[c][j] = 1.0 * (k - 1) / k * f[c ^ 1][j] +
                1.0 * j / k / (j + 1) * f[c ^ 1][j] +
                1.0 / k / (j + 1) * (f[c ^ 1][j + 1] + (1.0 + j) * j / 2.0 + j);
      if (f[c][j] <= 1e-100) f[c][j] = 0;
    }
  }
  printf("%.10lf", f[c][1] * k);
  return 0;
}
