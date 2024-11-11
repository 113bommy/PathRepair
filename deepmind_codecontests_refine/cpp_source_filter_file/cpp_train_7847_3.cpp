#include <bits/stdc++.h>
using namespace std;
const double TOLL = 1e-9;
int main() {
  long long a, b, m;
  while (cin >> a >> b >> m) {
    if (a >= m || b >= m) {
      cout << 0 << endl;
      continue;
    }
    if ((a + b) <= min(a, b)) {
      cout << -1 << endl;
      continue;
    }
    if (a > b) swap(a, b);
    long long ans = 0;
    if (a < 0) {
      long long dx = (-a + b - 1) / b;
      ans = dx;
      a = b + 1;
    }
    while (a < m && b < m) {
      if (a > b)
        b = a + b;
      else
        a = a + b;
      ans++;
    }
    cout << ans << endl;
  }
}
