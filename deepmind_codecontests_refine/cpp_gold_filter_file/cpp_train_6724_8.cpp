#include <bits/stdc++.h>
using namespace std;
int main() {
  int ara[100010], a, b, c, n;
  scanf("%d %d %d %d", &a, &b, &c, &n);
  for (int i = 0; i < n; i++) scanf("%d", &ara[i]);
  sort(ara, ara + n);
  int start = n, endi = -1, lo, hi, mid;
  lo = 0, hi = n - 1;
  while (hi - lo > 5) {
    mid = (lo + hi) / 2;
    if (ara[mid] > b)
      hi = mid;
    else
      lo = mid;
  }
  for (int i = lo; i <= hi; i++) {
    if (ara[i] > b) {
      start = i;
      break;
    }
  }
  lo = 0, hi = n - 1;
  while (hi - lo > 5) {
    mid = (lo + hi) / 2;
    if (ara[mid] < c)
      lo = mid;
    else
      hi = mid;
  }
  for (int i = hi; i >= lo; i--) {
    if (ara[i] < c) {
      endi = i;
      break;
    }
  }
  printf("%d\n", endi - start + 1);
  return 0;
}
