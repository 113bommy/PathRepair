#include <bits/stdc++.h>
const double inf = 1e20;
using namespace std;
long long gd(long long x, long long y) {
  if (x > y) swap(x, y);
  long long a = x, b = y, c;
  while (b % a) {
    c = b % a;
    b = a;
    a = c;
  }
  return y / a * x;
}
int main() {
  long long C, HR, HB, WR, WB;
  cin >> C >> HR >> HB >> WR >> WB;
  if (HR * WB == HB * WR) {
    if (WB < WR) swap(WB, WR), swap(HR, HB);
    long long ans1 = C / WB * HB, yu1 = C - C / WB * WB;
    for (long long i = 0; i <= min(C / WB, gd(WB, WR)); i++) {
      ans1 = max(ans1, C / WB * HB - HB * i + (i * WB + yu1) / WR * HR);
      if (!((C - WB * (C / WB - i)) % WR)) break;
    }
    cout << ans1;
    return 0;
  }
  if (C / max(WB, WR) < gd(WB, WR)) {
    if (WB < WR) swap(WB, WR), swap(HR, HB);
    long long ans1 = C / WB * HB, yu1 = C - C / WB * WB;
    ans1 = ans1 + yu1 / WR * HR;
    long long yu2 = yu1 - yu1 / WR * WR;
    for (long long i = 0; i <= C / WB; i++) {
      ans1 = max(ans1, C / WB * HB + yu1 / WR * HR - HB * i +
                           (i * WB + yu2) / WR * HR);
    }
    cout << ans1;
  } else {
    if (HR * WB > HB * WR) swap(WB, WR), swap(HR, HB);
    long long ans1 = C / WB * HB, yu1 = C - C / WB * WB;
    ans1 = ans1 + yu1 / WR * HR;
    long long yu2 = yu1 - yu1 / WR * WR;
    if (yu2) {
      for (long long i = 0; i <= min(C / WB, gd(WB, WR)); i++) {
        ans1 = max(ans1, C / WB * HB + yu1 / WR * HR - HB * i +
                             (i * WB + yu2) / WR * HR);
      }
    }
    cout << ans1;
  }
  return 0;
}
