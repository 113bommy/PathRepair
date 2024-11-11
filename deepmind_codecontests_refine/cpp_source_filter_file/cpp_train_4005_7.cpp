#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    long long ll = l, rr = r, lnl = 1, lnr = 1;
    while (ll >= 2) {
      lnl++;
      ll /= 2;
    }
    while (rr >= 2) {
      lnr++;
      rr /= 2;
    }
    bool flag = 0;
    for (int i = 0; i < lnr; i++) {
      if (r & (1ll << i)) {
        flag = 1;
      } else {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << r << "\n";
      continue;
    }
    if (lnr > lnl) {
      cout << (1ll << lnr - 1) - 1 << "\n";
      continue;
    }
    if (lnr == lnl) {
      int bt = 62;
      int x = 0;
      ;
      for (int i = 62; i >= 0; i--) {
        if ((l & (1ll << i)) != (r & (1ll << i))) {
          x = i;
          break;
        }
      }
      int ans = l;
      for (int i = 0; i <= x; i++) {
        l = l | (1ll << i);
        if (l <= r) {
          ans = l;
        }
      }
      cout << ans << "\n";
    }
  }
}
