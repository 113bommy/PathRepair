#include <bits/stdc++.h>
using namespace std;
int n, p, q;
double a[110000], b[110000];
int main() {
  double down, up = 1E9 + 10, t;
  int flag = 0;
  scanf("%d%d%d", &n, &p, &q);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", a + i, b + i);
    a[i] /= p;
    b[i] /= q;
    up = min(up, max(1 / a[i], 1 / b[i]));
  }
  down = 0;
  for (int j = 0; j < 100; j++) {
    t = (down + up) / 2;
    flag = 0;
    double k1 = -t, k2 = t;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        if (1 / a[i] <= t) {
          flag = 1;
          break;
        }
      } else
        ;
      if (a[i] > b[i]) k1 = max(k1, (a[i] + b[i] - 2 / t) / (a[i] - b[i]));
      if (a[i] < b[i]) k2 = min(k2, (a[i] + b[i] - 2 / t) / (a[i] - b[i]));
    }
    if (k1 >= k2 || flag)
      up = t;
    else
      down = t;
  }
  printf("%lf\n", t);
}
