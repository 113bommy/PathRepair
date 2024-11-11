#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  int a, b, c, d, e, f;
  long long sum;
  while (~scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)) {
    if (e > f) {
      sum = min(a, d) * e + min(b, min(c, d - min(a, b))) * f;
    } else {
      sum = min(b, min(c, d)) * f + min(a, d - min(b, min(c, d))) * e;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
