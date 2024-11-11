#include <bits/stdc++.h>
using namespace std;
long long a, b, ans;
long long cj(long long x) {
  if (x == 1)
    return 1;
  else {
    long long y = a;
    while (y % b == 0) {
      y /= x;
    }
    return y;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &a, &b);
    if (a % b != 0)
      ans = a;
    else {
      ans = 1;
      for (long long i = 1; i <= sqrt(b); i++) {
        if (b % i) continue;
        if (b % i == 0) {
          ans = max(ans, cj(i));
          ans = max(ans, cj(b / i));
        }
      }
    }
    printf("%lld\n", ans);
  }
}
