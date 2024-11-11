#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n, m, k;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &k);
  k++;
  if (k <= n) {
    printf("%lld 1", k);
    return 0;
  }
  if (k <= n + m - 1) {
    k -= n;
    printf("%lld", n, k);
    return 0;
  }
  k -= n + m - 1;
  long long int row = n - (k / (m - 1));
  if (k % (m - 1) != 0) {
    row--;
  }
  long long int x = k / (m - 1);
  if (k % (m - 1) == 0) {
    x--;
  }
  if (x % 2 == 0) {
    k = k % (m - 1);
    if (k == 0) {
      printf("%lld 2", row);
      return 0;
    }
    printf("%lld %lld", row, m - k + 1);
    return 0;
  } else {
    k = k % (m - 1);
    if (k == 0) {
      printf("%lld %lld", row, m);
      return 0;
    }
    printf("%lld %lld", row, k + 1);
    return 0;
  }
}
