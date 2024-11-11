#include <bits/stdc++.h>
using namespace std;
int search(long long left, long long right, long long desired, int maxEl) {
  long long mid = left + (right - left) / 2ll;
  if (desired < mid) return search(left, mid - 1, desired, maxEl - 1);
  if (desired > mid) return search(mid, right + 1, desired, maxEl - 1);
  return maxEl;
}
int main() {
  int n = 0;
  long long k = 0;
  scanf("%d%I64d", &n, &k);
  long long right = 1;
  for (int i = 1; i < n; ++i) {
    right = right * 2ll + 1;
  }
  printf("%d", search(1ll, right, k, n));
  return 0;
}
