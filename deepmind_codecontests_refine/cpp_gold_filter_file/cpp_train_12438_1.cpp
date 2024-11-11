#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
double EPS = 1e-8;
int n, arr[N];
bool ok(double d) {
  double last = 0.0;
  int used = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > last) {
      used++;
      last = arr[i] + 2 * d;
    }
  }
  return used <= 3;
}
double binarysearch() {
  double lo = 0, hi = 2e9 + 10, mid;
  while (hi - lo > EPS) {
    mid = (hi + lo) / 2;
    if (ok(mid))
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  double d = binarysearch();
  printf("%.7f\n", d);
  double last = 0.0;
  int used = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] - last > EPS) {
      used++;
      printf("%.7f ", arr[i] + d);
      last = arr[i] + 2 * d;
    }
  }
  while (used < 3) {
    printf("%.7f ", 0.0);
    used++;
  }
  puts("");
  return 0;
}
