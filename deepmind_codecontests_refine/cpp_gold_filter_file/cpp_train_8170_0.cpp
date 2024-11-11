#include <bits/stdc++.h>
using namespace std;
long double x, y, t, i;
long double bas, son, ans;
int main() {
  cin >> x >> y;
  if (y > x) {
    cout << -1 << '\n';
    return 0;
  }
  long double a = sqrt(y * y * 2);
  int t = (x + y) / y;
  if (t % 2 == 0)
    ans = y + (x + y - t * y) / (t);
  else
    ans = y + (y + x + y - t * y) / ((t - 1));
  if (ans > 1000000007 or ans < 0)
    cout << -1 << '\n';
  else
    cout << setprecision(15) << fixed << ans << '\n';
}
