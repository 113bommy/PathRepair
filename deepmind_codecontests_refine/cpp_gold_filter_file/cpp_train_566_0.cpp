#include <bits/stdc++.h>
int main() {
  long long n, x, y, t;
  long long high, low, mid, a;
  scanf("%lld%lld%lld", &n, &x, &y);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &t);
    high = 1e15, low = 0;
    while (low <= high) {
      mid = (high + low) / 2;
      if (mid / x + mid / y < t)
        low = mid + 1;
      else {
        a = mid;
        high = mid - 1;
      }
    }
    if (a % x == 0 && a % y == 0)
      printf("Both\n");
    else if (a % y)
      printf("Vova\n");
    else
      printf("Vanya\n");
  }
  return 0;
}
