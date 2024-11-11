#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, br = 1, ans = 1, j = 0;
  scanf("%I64d %I64d", &n, &k);
  if (k * 2 > n) k = n - k;
  for (long long i = 1; j < n; i += k) {
    if ((i / n != (i + k) / n || i % n == 0) && (i + k) % n > 1) {
      ans += br + 1;
      br += 2;
      printf("%I64d ", ans);
    } else {
      ans += br;
      printf("%I64d ", ans);
    }
    j++;
  }
  return 0;
}
