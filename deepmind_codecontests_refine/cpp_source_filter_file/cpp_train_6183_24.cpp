#include <bits/stdc++.h>
using namespace std;
int main() {
  long double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  long long z = d;
  long double l7ad_eleshara = d / v;
  if (l7ad_eleshara <= g)
    cout << fixed << setprecision(10) << l / v << endl;
  else {
    long double z = d;
    long double time = 0;
    long long dis = min(d, v * (g + r));
    time += max(r + g, dis / v);
    d -= dis;
    while (d > 0) {
      long long temp;
      l7ad_eleshara = (z - d) / v;
      if (l7ad_eleshara > g) {
        time += r + g;
        temp = min(d, v * (g + r));
        d -= temp;
      } else {
        time += l7ad_eleshara;
        d = 0;
      }
    }
    time += (l - z) / v;
    cout << fixed << setprecision(10) << time << endl;
  }
}
