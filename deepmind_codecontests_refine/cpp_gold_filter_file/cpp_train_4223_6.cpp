#include <bits/stdc++.h>
using namespace std;
int main() {
  long long d, m, a, b, t;
  cin >> d >> m >> a >> b >> t;
  cout << (((a * m + t - b * m) > 0)
               ? min(b * d, (m < d ? a * m + b * d - b * m : a * d))
               : min(((d / m) * (a * m + t - b * m) + b * d -
                      (d / m == 0 ? 0 : t)),
                     (a * d + t * (d / m))));
  return 0;
}
