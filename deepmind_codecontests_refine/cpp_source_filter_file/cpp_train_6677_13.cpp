#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, z, a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    if (x == 1) {
      cout << y << endl;
    } else {
      a = min(y, z);
      if (a == y) {
        cout << x * y << endl;
      } else {
        b = (x / 2) * z;
        c = (x % 2) * y;
        cout << b + c << endl;
      }
    }
  }
  return 0;
}
