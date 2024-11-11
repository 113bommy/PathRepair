#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, aa, bb;
  double s, s1, a, b, ans;
  cin >> t;
  for (i = 1; i <= t; i++) {
    cin >> aa >> bb;
    a = (double)aa;
    b = (double)bb;
    s = 2 * a * b;
    s1 = a * b;
    if (aa - 4 * bb >= 0) {
      s1 += (a - 4.0 * b) * b;
      s1 += 2.0 * b * b;
    } else {
      s1 += a * a / 8.0;
    }
    if (aa == 0 && bb > 0)
      ans = 0.5;
    else if (bb == 0)
      ans = 1.0;
    else if (aa == 0 && bb == 0)
      ans = 1.0;
    else
      ans = s1 / s;
    printf("%.9lf\n", ans);
  }
  return 0;
}
