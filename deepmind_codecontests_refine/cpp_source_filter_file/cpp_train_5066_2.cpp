#include <bits/stdc++.h>
int main() {
  long long int n, m;
  scanf("%lld%lld", &n, &m);
  long long int a[n + 1], x;
  a[0] = 0;
  for (long long int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    a[i] = a[i - 1] + x;
  }
  for (long long int i = 0; i < m; i++) {
    long long int lb = 1, ub = n, mid, k;
    scanf("%lld", &k);
    while (lb <= ub) {
      mid = (lb + ub) / 2;
      if (mid == 1 && a[mid] > k)
        break;
      else if (a[mid] > k && a[mid - 1] <= k)
        break;
      else if (a[mid] == k)
        break;
      else if (a[mid - 1] > k)
        ub = mid - 1;
      else
        lb = mid + 1;
    }
    printf("%lld %lld\n", mid, (k - a[mid - 1]));
  }
  return 0;
}
