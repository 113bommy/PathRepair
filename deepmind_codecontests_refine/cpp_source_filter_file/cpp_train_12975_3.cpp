#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  int x[1009];
  double y[1009];
  scanf("%d%d", &n, &r);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  y[0] = r * 1.0;
  for (int i = 1; i < n; i += 1) {
    double h = 0;
    for (int j = 0; j < i; j++)
      h = max(h, y[j] + sqrt(4 * 1.0 * r * r -
                             (x[i] - x[j]) * 1.0 * (x[i] - x[j])));
    y[i] = h;
  }
  for (int i = 0; i < n; i++) printf("%0.9lf ", y[i]);
}
