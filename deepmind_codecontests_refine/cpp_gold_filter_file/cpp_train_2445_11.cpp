#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  while (n--) {
    long long l, t, m;
    cin >> l >> t >> m;
    if (a + (l - 1) * b > t) {
      cout << -1 << endl;
      continue;
    }
    long long s = 1, e = 1e12;
    while (e >= s) {
      long long mm = (e + s) / 2;
      double big = ((1.0 * mm) / 2) * (2 * a + (mm - 1) * b) -
                   ((1.0 * (l - 1)) / 2) * (2 * a + (l - 2) * b);
      if (a + (mm - 1) * b > t || big > m * t)
        e = mm - 1;
      else
        s = mm + 1;
    }
    cout << e << endl;
  }
}
