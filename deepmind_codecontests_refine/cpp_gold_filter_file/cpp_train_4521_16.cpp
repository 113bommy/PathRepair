#include <bits/stdc++.h>
using namespace std;
const int D = 1e6;
int n, k;
double a[D + 1];
int main() {
  scanf("%d%d", &n, &k);
  int m = D / k, x1, x2;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x1);
    double ans = 0;
    for (int j = 0; j < k; j++) {
      scanf("%d", &x2);
      double r = (double)(x2 - x1) / m;
      for (int l = 0; l <= m; l++) {
        double delta = (double)x1 + r * l;
        if (a[j * m + l] < delta) {
          ans += delta - a[j * m + l];
          a[j * m + l] = delta;
        }
      }
      x1 = x2;
    }
    printf("%lf\n", ans / m);
  }
}
