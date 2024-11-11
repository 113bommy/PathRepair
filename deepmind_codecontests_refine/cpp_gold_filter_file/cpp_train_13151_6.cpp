#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, m, A, d;
  double t, t1 = 0, t2, t3;
  scanf("%d%d%d", &n, &A, &d);
  int a[100009][2];
  for (i = 0; i < n; ++i) scanf("%d%d", &a[i][0], &a[i][1]);
  t = sqrt(2.0 * d / (double)A);
  for (i = 0; i < n; ++i) {
    t3 = min(a[i][1] / (double)A, t);
    t2 = (d - A * t3 * t3 / 2.0) / (double)a[i][1];
    t1 = max(t1, t2 + t3 + a[i][0]);
    printf("%0.5lf\n", t1);
  }
}
