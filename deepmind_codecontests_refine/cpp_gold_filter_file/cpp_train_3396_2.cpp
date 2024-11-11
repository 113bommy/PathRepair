#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, f, k, ans = 0;
  cin >> a >> b >> f >> k;
  if ((f * 2) > b && k > 2 || (a - f) * 2 > b && k > 1 || f > b || (a - f) > b)
    cout << -1;
  else {
    long long x = b;
    for (int i = 1; i < k; i++) {
      if (i % 2 == 1) {
        if (a + (a - f) > x) {
          ans++;
          x = b - (a - f);
        } else
          x -= a;
      } else {
        if (a + f > x) {
          ans++;
          x = b - f;
        } else
          x -= a;
      }
    }
    if (a > x) ans++;
    cout << ans;
  }
  return 0;
}
