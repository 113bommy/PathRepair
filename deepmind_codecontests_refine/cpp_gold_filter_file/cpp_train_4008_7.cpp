#include <bits/stdc++.h>
using namespace std;
double low, high, mid, res, w;
int k, i, n, arr[200010];
int func(double val) {
  if (((double)arr[0]) >= val && ((double)arr[n]) >= (2.0 * val)) {
    return 1;
  }
  return 0;
}
int main() {
  scanf(" %d %lf", &n, &w);
  for (i = 0; i < (n * 2); i++) {
    scanf(" %d", &arr[i]);
  }
  sort(arr, arr + (n * 2));
  low = 0.0;
  high = w / 3.0;
  res = 0.0;
  k = 0;
  while ((low + 0.0000000000000001) <= high && k < 300) {
    k++;
    mid = (low + high) / 2.0;
    if (func(mid) && (mid * 3.0 * n) <= w) {
      res = max(res, mid);
      low = mid;
    } else
      high = mid;
  }
  printf("%.10lf\n", res * 3.0 * n);
  return 0;
}
