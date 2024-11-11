#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long c1, c2, x, y;
  while (cin >> c1 >> c2 >> x >> y) {
    long long l = 1;
    long long r = 1000000000;
    while (l <= r) {
      long long m = (l + r) / 2;
      if (m - m / x >= c1 && m - m / y >= c2 && m - m / (x * y) >= (c1 + c2)) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << l << endl;
  }
}
