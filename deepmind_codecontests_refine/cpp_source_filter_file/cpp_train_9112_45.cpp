#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int high = n - 1;
  int lo = 0;
  int mid = 0;
  int xt = 0;
  int rt = 0;
  int o = 0;
  if (n >= 2) {
    while (lo <= high) {
      mid = lo + (high - lo + 1) / 2;
      if (high - lo <= 1) {
        break;
      }
      xt = 0;
      rt = 0;
      for (int i = 0; i < mid; i++) {
        rt = rt + a[mid] - a[i];
      }
      for (int i = mid + 1; i < n; i++) {
        xt = xt + a[i] - a[mid];
      }
      if (xt * (1.0 - k / 100.0) == rt) {
        printf("%f", double(a[mid]));
        o = 1;
        break;
      }
      if (xt * (1.0 - k / 100.0) > rt) {
        lo = mid;
      }
      if (xt * (1.0 - k / 100.0) < rt) {
        high = mid;
      }
    }
    rt = 0;
    xt = 0;
    if (o != 1) {
      for (int i = 0; i <= lo; i++) {
        rt = rt + a[i];
      }
      for (int i = high; i < n; i++) {
        xt = xt + a[i];
      }
      double ans = (xt * (1.0 - k / 100.0) + rt) /
                   (lo + 1.0 + (n - high) * (1.0 - k / 100.0));
      printf("%f", ans);
    }
  } else if (n == 1) {
    printf("%f", a[0]);
  }
  return 0;
}
