#include <bits/stdc++.h>
using namespace std;
int arr[10002];
int n, k;
bool istrue(double val) {
  double res = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > val) {
      double exceed = arr[i] - val;
      exceed -= (k * exceed) / 100.0;
      res += exceed;
    } else
      res -= val - arr[i];
  }
  return res < 1e-6;
}
int main() {
  scanf("%d%d", &n, &k);
  double mn = 1e9, mx = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    mn = min(mn, (double)arr[i]);
    mx = max(mx, (double)arr[i]);
  }
  double ans;
  for (int bs = 0; bs < 100; ++bs) {
    double mid = mn + (mx - mn) / 2.0;
    if (istrue(mid))
      ans = mx = mid;
    else
      mn = mid;
  }
  printf("%.9lf\n", ans + 1e-6);
  return 0;
}
