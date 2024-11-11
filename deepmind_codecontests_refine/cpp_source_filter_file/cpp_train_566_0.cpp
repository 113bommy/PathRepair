#include <bits/stdc++.h>
int main() {
  long long n, x, y, a;
  scanf("%lld%lld%lld", &n, &x, &y);
  while (n--) {
    scanf("%lld", &a);
    long long l = 0, r = 1LL << 33, mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (mid / x + mid / y >= a)
        r = mid - 1;
      else
        l = mid + 1;
    }
    mid = r + 1;
    if (mid % x == 0 && mid % y == 0)
      puts("Both");
    else if (mid % y == 0)
      puts("Vanya");
    else
      puts("Vova");
  }
  return 0;
}
