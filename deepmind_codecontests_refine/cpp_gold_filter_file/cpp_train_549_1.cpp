#include <bits/stdc++.h>
using namespace std;
long long const oo = 8e18;
int const ooi = 2e9;
int const N = 2e5 + 100;
int const M = 1e6 + 100;
int const MOD = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  int vp, vd, t, f, c, b = 0, dd = 0;
  double dp = 0;
  cin >> vp >> vd >> t >> f >> c;
  dp += vp * t;
  while (dp < c) {
    if (vp >= vd) break;
    double x = (dd - dp) / (vp - vd);
    dp += x * vp;
    dd += x * vd;
    if (dp >= c) break;
    ++b;
    dp += dp / vd * vp + f * vp;
    dd = 0;
  }
  cout << b << endl;
  return 0;
}
