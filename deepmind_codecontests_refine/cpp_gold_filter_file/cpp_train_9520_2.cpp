#include <bits/stdc++.h>
using namespace std;
double p[200];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
  }
  sort(p, p + n);
  double k = 0.0, t = 1.0;
  for (int i = n - 1; i >= 0; i--) {
    if (k - t > (1e-11)) break;
    k = k * (1.0 - p[i]) + t * p[i];
    t *= (1 - p[i]);
  }
  printf("%.12lf\n", k);
  return 0;
}
