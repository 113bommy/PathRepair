#include <bits/stdc++.h>
using namespace std;
const unsigned long long MOD = 257;
int main() {
  std::ios::sync_with_stdio(false);
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double ans = 0;
  if (v * g >= d)
    ans = l / v;
  else {
    l -= d;
    double t = d / v;
    ans = t;
    double tt = g + r;
    int flag = 0;
    while (t > 0) {
      t -= g;
      if (t > 0) {
        t -= r;
      }
      if (t < 0) flag = 1;
    }
    if (flag == 1) {
      ans -= t;
    }
    ans += l / v;
  }
  printf("%.7f\n", ans);
}
