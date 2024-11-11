#include <bits/stdc++.h>
using namespace std;
int a[200005], n;
double judge(double x) {
  double ret = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i] - x;
    if (sum < 0)
      sum = 0;
    else {
      ret = max(ret, sum);
    }
  }
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += x - a[i];
    if (sum < 0)
      sum = 0;
    else {
      ret = max(ret, sum);
    }
  }
  return ret;
}
int main() {
  double l = 10000, r = -10000, mid, mid1, mid2, t, t1, t2;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    l = min(l, 1.0 * a[i]);
    r = max(r, 1.0 * a[i]);
  }
  while (1) {
    mid = (l + r) / 2;
    mid1 = mid - (1e-10);
    mid2 = mid + (1e-10);
    t = judge(mid);
    t1 = judge(mid1);
    t2 = judge(mid2);
    if (t < t1) {
      if (t < t2) {
        break;
      } else {
        l = mid2;
      }
    } else {
      r = mid1;
    }
  }
  printf("%.8lf", t);
  return 0;
}
