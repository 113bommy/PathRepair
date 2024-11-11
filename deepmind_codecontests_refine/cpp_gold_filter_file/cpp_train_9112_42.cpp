#include <bits/stdc++.h>
int n;
double k, num[10005], l, r, ans;
double cal(double mid) {
  int i;
  double ret = 0;
  for (i = 1; i <= n; i++) {
    if (num[i] - mid > -1e-9) {
      ret = ret + (num[i] - mid) * (100.0 - k) / 100.0;
    } else {
      ret = ret - (mid - num[i]);
    }
  }
  return ret;
}
double search() {
  double mid, temp;
  while (l - r < -1e-9) {
    mid = (l + r) / 2;
    temp = cal(mid);
    if (temp > 1e-9) {
      l = mid;
    } else if (temp < -1e-9) {
      r = mid;
    } else {
      return mid;
    }
  }
  return l;
}
int main() {
  int i, j;
  while (scanf("%d%lf", &n, &k) != EOF) {
    l = 2000, r = -1, ans = -1;
    for (i = 1; i <= n; i++) {
      scanf("%lf", &num[i]);
      l = l - num[i] > 1e-9 ? num[i] : l;
      r = num[i] - r > 1e-9 ? num[i] : r;
    }
    ans = search();
    printf("%lf\n", ans);
  }
}
