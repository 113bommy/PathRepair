#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int k, q;
double f[10100][1100], pi;
int main() {
  scanf("%d %d", &k, &q);
  f[1][1] = 1;
  for (int i = 2; i < (k + 1) * 8; i++) {
    for (int j = 1; j < min(i, k) + 1; j++) {
      f[i][j] = f[i - 1][j - 1] * (k - j + 1) / k + f[i - 1][j] * j / k;
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%lf", &pi);
    pi = (pi - eps) / 2000;
    for (int j = k; j < (k + 1) * 8; j++)
      if (f[j][k] >= pi) {
        printf("%d\n", j);
        break;
      }
  }
  return 0;
}
