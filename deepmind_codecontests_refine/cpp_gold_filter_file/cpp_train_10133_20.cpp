#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main() {
  int n, a, d;
  cin >> n >> a >> d;
  double last = -1e100;
  for (int i = 0; i < n; i++) {
    int t, v;
    scanf("%d%d", &t, &v);
    double delta = v * 1.0 * v * 1.0 / 2 / a;
    if (delta < d)
      last = max(last, t + v * 1.0 / a + (d - delta) * 1.0 / v);
    else
      last = max(last, t + sqrt(2 * d * 1.0 / a));
    printf("%.10f\n", last);
  }
  return 0;
}
