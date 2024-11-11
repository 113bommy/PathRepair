#include <bits/stdc++.h>
using namespace std;
int main() {
  double x, y;
  int n;
  double t;
  int temp;
  double a[122];
  double maxt, va, vb;
  while (~scanf("%d%lf%lf", &n, &va, &vb)) {
    temp = 2;
    for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
    scanf("%lf%lf", &x, &y);
    maxt = a[1] / va + sqrt((x - a[1]) * (x - a[1]) + y * y) / vb;
    for (int i = 1; i < n; i++) {
      t = a[i] / va;
      t += sqrt((x - a[i]) * (x - a[i]) + y * y) / vb;
      if (t < maxt) {
        maxt = t;
        temp = i + 1;
      }
    }
    printf("%d\n", temp);
  }
  return 0;
}
