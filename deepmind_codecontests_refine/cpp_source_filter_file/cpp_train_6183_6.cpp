#include <bits/stdc++.h>
using namespace std;
const long long int big = 1000000009;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long double l, d, v, g, r;
  cin >> l >> d >> v >> g;
  cin >> r;
  long double dg = g * v, at = d / v, tt = at;
  if (dg >= l) {
    at = l / v;
    cout << setprecision(6) << at << endl;
  } else {
    long double x = 0, y = g + r;
    while (1) {
      if (at >= x && at <= y) {
        break;
      }
      x = y;
      y = y + (g + r);
    }
    if (x + g <= at) {
      tt = tt + (y - at);
    }
    tt = tt + (l - d) / v;
    cout << setprecision(6) << tt << endl;
  }
  return 0;
}
