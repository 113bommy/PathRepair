#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, y1, z1;
    long long x2, y2, z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    long long sum = 0;
    if (z2 > x1) {
      z2 -= x1;
      if (z2 > z1) {
        z2 -= z1;
        sum -= (2 * z2);
      } else {
        z1 -= z2;
        sum += 2 * min(z1, y2);
      }
    } else {
      sum += 2 * min(z1, y2);
    }
    cout << sum << endl;
  }
  return 0;
}
