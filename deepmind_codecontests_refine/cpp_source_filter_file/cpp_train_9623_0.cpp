#include <bits/stdc++.h>
using namespace std;
long long ans, n;
long long x[1007000];
long long s[1007000];
void init() {
  long long i, j, k;
  x[0] = 0;
  for (long long i = 1; i <= 1000010; i++) {
    x[i] = x[i - 1] ^ i;
  }
  for (i = 1; i <= n; i++) {
    long long tmp = i * 2 - 1;
    long long m = n % tmp;
    if (m >= i - 1) {
      ans ^= x[i - 1];
      m -= i;
      if (m > 0) ans ^= x[m];
    } else {
      ans ^= x[m];
    }
  }
}
int main() {
  long long i, j, k;
  while (scanf("%lld", &n) != EOF) {
    ans = 0;
    for (i = 1; i <= n; i++) {
      scanf("%lld", &s[i]);
      ans ^= s[i];
    }
    init();
    printf("%lld\n", ans);
  }
  return 0;
}
