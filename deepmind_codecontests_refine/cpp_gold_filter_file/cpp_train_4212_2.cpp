#include <bits/stdc++.h>
using namespace std;
const int N = 105;
double a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lf", &a[i]);
  sort(a, a + n);
  double s = 0, p = 1, ans = 0;
  if (1.0 - a[n - 1] <= 1e-9) return printf("1\n"), 0;
  for (int i = n - 1; i >= 0; --i) {
    s += a[i] / (1 - a[i]);
    p *= (1 - a[i]);
    ans = max(ans, p * s);
    if (s >= 1) break;
  }
  printf("%.9f\n", ans);
  return 0;
}
