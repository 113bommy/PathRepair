#include <bits/stdc++.h>
using namespace std;
double f[100010UL][2];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int blo = 526;
  double p1 = (double)(k - 1) / (double)k, p2 = 1. / (double)k;
  int lt = 1, nw = 0;
  for (int i = 1; i <= n; ++i) {
    lt ^= 1, nw ^= 1;
    for (int j = 1; j <= blo; ++j) {
      f[nw][j] = p1 * f[lt][j] +
                 p2 * ((double)j / (j + 1) * (f[lt][j] + (double)(j + 1) / 2.) +
                       1. / (double)(j + 1) * (f[lt][j + 1] + (double)j));
    }
  }
  printf("%.10lf", f[nw][1] * k);
  return 0;
}
