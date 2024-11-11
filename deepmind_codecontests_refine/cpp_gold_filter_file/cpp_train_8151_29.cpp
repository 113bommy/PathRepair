#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  long long a, b, c, d, e, f, g, h;
  long long lim = 0, tost = 0, laym = 0, sol = 0, min1 = 0, min2 = 0;
  cin >> a >> b >> c >> d >> e >> f >> g >> h;
  lim = b * c;
  tost = lim / g;
  laym = d * e;
  sol = f / h;
  min1 = min(tost, laym);
  min2 = min(min1, sol);
  cout << min2 / a;
}
