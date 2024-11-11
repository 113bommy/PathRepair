#include <bits/stdc++.h>
using namespace std;
inline double calc(double l1, double r1, double l2, double r2) {
  return max(min(r1, r2) - max(l1, l2), 0.0);
}
int main() {
  int nf, ne, ns;
  double rf, re, rs;
  int df, de;
  cin >> nf >> ne >> ns >> rf >> re >> rs >> df >> de;
  rf = sqrt(rf * rf - 1);
  re = sqrt(re * re - 1);
  rs = sqrt(rs * rs - 1);
  int n = nf + ne + ns;
  double ans = 0.0;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (__builtin_popcount(mask) != ns) continue;
    double val = 0.0;
    vector<double> vv;
    for (int sub = ((1 << n) - 1) ^ mask; sub; sub -= sub & -sub) {
      int p1 = __builtin_ctz(sub) >> 1;
      double drf = df * rf * 2;
      double dre = de * re * 2;
      for (int sub2 = mask; sub2; sub2 -= sub2 & -sub2) {
        int p2 = __builtin_ctz(sub2) >> 1;
        drf += df * calc(p1 - rs, p1 + rs, p2 - rf, p2 + rf);
        dre += de * calc(p1 - rs, p1 + rs, p2 - re, p2 + re);
      }
      val += drf;
      vv.push_back(drf - dre);
    }
    sort(vv.begin(), vv.end());
    for (int i = 0; i < ne; i++) val -= vv[i];
    ans = max(ans, val);
  }
  cout << fixed << setprecision(3) << ans << '\n';
  return 0;
}
