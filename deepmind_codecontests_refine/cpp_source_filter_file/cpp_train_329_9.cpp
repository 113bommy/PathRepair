#include <bits/stdc++.h>
using namespace std;
long long n, p, w, d, xmax, xmin, tmp, y;
int main() {
  cin >> n >> p >> w >> d;
  if (p >= n * w)
    cout << -1 << endl;
  else {
    xmax = p / w;
    if (xmax - 1e7 > 0)
      xmin = xmax - 1e7;
    else
      xmin = 0;
    for (long long i = xmax; i >= xmin; i--) {
      tmp = p - i * w;
      if (tmp % d == 0 && i + tmp / d <= n) {
        y = tmp / d;
        cout << i << ' ' << y << ' ' << n - i - y << endl;
        return 0;
      }
    }
    cout << -1 << endl;
  }
}
