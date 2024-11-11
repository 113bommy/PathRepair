#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x0, n, t;
  cin >> t;
  while (t--) {
    cin >> x0 >> n;
    if (x0 % 2 == 0) {
      if (n % 4 == 1) {
        x0 = x0 - 1 - n / 4 * (4);
        cout << x0 << endl;
      } else if (n % 4 == 2)
        cout << x0 + 1 << endl;
      else if (n % 4 == 3)
        cout << (x0 + 4 + n / 4 * 4) << endl;
      else if (n % 4 == 0)
        cout << x0 << endl;
    } else if (x0 % 2 != 0) {
      if (n % 4 == 1)
        cout << x0 + 1 + n / 4 * 4 << endl;
      else if (n % 4 == 2)
        cout << x0 - 1 << endl;
      else if (n % 4 == 3)
        cout << (x0 - 4 + n / 4 * (-4)) << endl;
      else if (n % 4 == 0)
        cout << x0 << endl;
    }
  }
  return 0;
}
