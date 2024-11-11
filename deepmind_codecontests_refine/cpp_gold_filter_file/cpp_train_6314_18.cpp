#include <bits/stdc++.h>
using namespace std;
long long n, q, ans, x, nn;
int main() {
  scanf("%lld%lld", &n, &q);
  while (q--) {
    scanf("%lld", &x);
    nn = n;
    ans = 0;
    while (nn > 1) {
      if ((x & 1)) {
        ans = nn - (x >> 1);
        break;
      }
      x = (x >> 1) + (nn & 1);
      nn = nn + 1 >> 1;
    }
    if (!ans) ans = 1;
    printf("%lld\n", n + 1 - ans);
  }
}
