#include <bits/stdc++.h>
int main() {
  int N;
  long long n, r;
  long long res;
  scanf("%d", &N);
  while (N--) {
    res = 0;
    scanf("%lld %lld", &n, &r);
    if (r >= n) {
      res += 1;
      r = n - 1;
    }
    res = (r + 1) * r / 2;
    printf("%lld\n", res);
  }
  return 0;
}
