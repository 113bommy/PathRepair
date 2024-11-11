#include <bits/stdc++.h>
using namespace std;
int n, a[5555], b[5555], c[5555];
double d[5555], res = 1e18;
int sq(int x) { return x * x; }
double dis(int x, int y) {
  return sqrt(sq(a[x] - a[y]) + sq(b[x] - b[y]) + sq(c[x] - c[y]));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  for (int i = 1; i < n; i++) d[i] = dis(0, i);
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      double x = dis(i, j) + d[i] + d[j];
      res = min(res, x);
    }
  printf("%.6lf\n", res / 2);
  return 0;
}
