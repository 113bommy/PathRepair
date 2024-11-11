#include <bits/stdc++.h>
using namespace std;
long long l, r, m;
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    cin >> l >> r >> m;
    long long a, b, c;
    if (l > m) {
      for (long long i = l; i <= r; ++i) {
        long long x = i - m;
        if (x <= (r - l)) {
          cout << i << " " << l << " " << l + x << endl;
          break;
        }
      }
    } else {
      for (long long i = l; i <= r; ++i) {
        long long x = m % i, y = i - x;
        if (x <= (r - l)) {
          cout << i << " " << l + x << " " << l << endl;
          break;
        }
        if (y <= (r - l)) {
          cout << i << " " << l << " " << l + y << endl;
          break;
        }
      }
    }
  }
  return 0;
}
