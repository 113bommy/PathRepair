#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, d;
  cin >> t;
  while (t--) {
    cout << setprecision(15);
    cin >> d;
    if (d == 0)
      cout << "Y " << 0.0 << ' ' << 0.0 << '\n';
    else if (d < 4)
      cout << "N\n";
    else {
      cout << "Y ";
      double det = sqrt(d * d - 4 * d) * 1.0;
      double x, y;
      x = d + det;
      y = d - det;
      x /= 2;
      y /= 2;
      cout << x << ' ' << y << '\n';
    }
  }
}
