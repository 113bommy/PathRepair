#include <bits/stdc++.h>
using namespace std;
long long h, n, ans;
int main() {
  scanf("%lld%lld", &h, &n);
  long long r = 0, b = 1, e = 1ll << h, a = (1ll << (h + 1)) - 1;
  while (b < e) {
    if ((b + e) / 2 < n) {
      b = (b + e) / 2 + 1;
      if (!r)
        ans += a / 2;
      else
        r = r xor 1;
    } else {
      e = (b + e) / 2;
      if (r)
        ans += a / 2;
      else
        r = r xor 1;
    }
    ans++;
    a /= 2;
  }
  printf("%lld\n", ans);
  return 0;
}
