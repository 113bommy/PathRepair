#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    double a, b;
    cin >> a >> b;
    double total = 2.0 * a * b, fav = a * b;
    if (b == 0) {
      cout << 1.0 << '\n';
      continue;
    } else if (a == 0) {
      cout << 0.0 << '\n';
      continue;
    }
    double inter, temp;
    inter = 4.0 * b;
    if (inter < a) {
      temp = (0.5 * (a * (a / (4.0)))) -
             (0.5 * (a - (4.0) * b) * ((a / (4.0)) - b));
    } else {
      temp = (0.5 * a * (a / (4.0)));
    }
    fav += temp;
    double ans;
    ans = fav / total;
    cout.precision(12);
    cout << ans << '\n';
  }
  return 0;
}
