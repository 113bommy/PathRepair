#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
int a[N];
int n, k, x;
int p(int a, int b) {
  if (a == 0) return b / x;
  return b / x - (a - 1) / x;
}
int main() {
  scanf("%d %d %d", &n, &x, &k);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int lo = i, hi = n - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (p(a[i], a[mid]) < k)
        lo = mid + 1;
      else
        hi = mid;
    }
    if (p(a[i], a[lo]) != k) break;
    int l = lo;
    lo = i, hi = n - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (p(a[i], a[mid]) <= k)
        lo = mid;
      else
        hi = mid - 1;
    }
    if (p(a[i], a[i]) == k) {
      int lo2 = i, hi2 = n - 1;
      while (lo2 < hi2) {
        int mid = lo2 + (hi2 - lo2 + 1) / 2;
        if (a[mid] <= a[i])
          lo2 = mid;
        else
          hi2 = mid - 1;
      }
      ans += hi2 - i;
    }
    ans += lo - l + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
