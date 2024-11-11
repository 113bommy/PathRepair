#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, y, a, b;
    cin >> x >> y;
    cin >> a >> b;
    long long int ac = 0, bc = 0;
    if (x >= y) {
      if (a < 2 * b) {
        cout << (x + y) * a << endl;
      } else {
        ac = x - y;
        bc = y;
        cout << a * ac + b * bc << endl;
      }
    } else {
      if (a < 2 * b) {
        cout << (x + y) * a << endl;
      } else {
        ac = y - x;
        bc = x;
        cout << a * ac + b * bc << endl;
      }
    }
  }
  return 0;
}
