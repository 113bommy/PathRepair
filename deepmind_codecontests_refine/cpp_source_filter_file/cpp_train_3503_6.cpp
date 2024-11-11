#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, a, b;
  scanf("%lld %lld %lld %lld", &n, &k, &a, &b);
  long long int count = 0;
  if (k == 1) {
    printf("%d", a * (n - 1));
    return 0;
  }
  while (n >= k) {
    count += a * (n % k);
    n /= k;
    count += min(n * (k - 1) * a, b);
  }
  count += a * (n - 1);
  printf("%lld", count);
}
