#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a, d;
double calc(int t, int v) {
  if (2ll * a * d < 1ll * v * v) {
    return t + sqrt(2.0 * d / a);
  } else {
    return t + (double)v / a + (d - 0.5 * v / a * v) / v;
  }
}
int main() {
  scanf("%d%d%d", &n, &a, &d);
  double old = 0;
  for (int i = 0; i < n; ++i) {
    int t, v;
    scanf("%d%d", &t, &v);
    double tmp = calc(t, v);
    printf("%.10f\n", max(old, tmp));
    old = max(old, tmp);
  }
  return 0;
}
