#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, y, a, b;
    cin >> x >> y;
    cin >> a >> b;
    if (x < y) {
      if ((2 * x * a) < (x * b)) {
        cout << (x + y) * a << endl;
      } else {
        cout << ((b * x) + (y - x) * a) << endl;
      }
    } else {
      if ((2 * y * a) < (y * b)) {
        cout << (x + y) * a << endl;
      } else {
        cout << ((b * y) + (x - y) * a) << endl;
      }
    }
  }
}
