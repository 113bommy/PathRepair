#include <bits/stdc++.h>
int main() {
  long long int n, z;
  scanf("%lld", &n);
  double k;
  k = sqrt(n);
  {
    z = floor(k);
    if ((z) * (z) == n) {
      printf("%lld", 2 * z * 2);
      return 0;
    } else if (z * (z + 1) >= n && z * z < n)
      printf("%lld", 2 * (z + z + 1));
    else
      printf("%lld", 2 * (z + z + 2));
  }
}
