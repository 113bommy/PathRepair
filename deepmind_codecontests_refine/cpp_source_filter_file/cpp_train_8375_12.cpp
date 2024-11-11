#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l, r, ll, lll, x;
  cin >> n;
  while (n--) {
    scanf("%lld%lld", &l, &r);
    ll = l;
    lll = l;
    x = 1;
    for (int i = 0; i < 63; i++) {
      if (l % 2 == 0) ll += x;
      l /= 2;
      x = x << 1;
      if (ll >= r) {
        printf("%lld\n", lll);
        break;
      }
      lll = ll;
    }
  }
}
