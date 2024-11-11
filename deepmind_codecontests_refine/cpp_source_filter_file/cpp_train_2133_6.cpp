#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B, n;
  cin >> A >> B >> n;
  long long l, t, m;
  long long r;
  for (int i = 0; i < n; i++) {
    cin >> l >> t >> m;
    if (A + (l - 1) * B > t)
      cout << -1 << endl;
    else {
      long long p = l;
      r = (t - A) / B + 1;
      while (!((2 * A + B * (r + l - 2)) / 2.0 * (r - l + 1) <= t * m &&
               ((2 * A + B * (r + l)) / 2.0 * (r - l) > t * m))) {
        long long sr = (r + p) / 2;
        if ((2 * A + B * (r + l - 2)) / 2.0 * (r - l + 1) <= t * m) {
          p = sr;
        } else
          r = sr;
        if (r - p <= 1) {
          if ((2 * A + B * (r + l - 2)) / 2.0 * (r - l + 1) > t * m) {
            r = p;
          }
          break;
        }
      }
      cout << r << endl;
    }
  }
}
