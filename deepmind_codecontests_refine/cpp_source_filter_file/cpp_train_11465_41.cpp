#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  long double a, b, c, d;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> d;
    c = d * d - 4 * d;
    if (c < 0) {
      cout << "N" << endl;
      continue;
    }
    c = sqrt(c);
    a = (d + c) / (2.0);
    b = (d - c) / (2.0);
    cout << fixed;
    cout << setprecision(8);
    cout << "Y"
         << " " << a << " " << b << endl;
  }
  return 0;
}
