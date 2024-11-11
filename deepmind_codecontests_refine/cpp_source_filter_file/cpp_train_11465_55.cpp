#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long double d, c;
    cin >> d;
    c = 4;
    cout << setprecision(9);
    if (d < c && d > 0)
      cout << "N" << '\n';
    else {
      c = sqrt(d * d - 4 * d);
      cout << "Y" << ' ' << (d - c) / 2.0 << ' ' << (d + c) / 2.0 << '\n';
    }
  }
  return 0;
}
