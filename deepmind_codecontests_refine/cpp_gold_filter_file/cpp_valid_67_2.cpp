#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 0;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long a = 0, b = 0, c = 0, diff = 0, n = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    diff = abs(a - b);
    n = 2 * diff;
    if (c - diff >= 1 && n >= a && n >= b && n >= c) {
      cout << c - diff << endl;
    } else if (c + diff <= n && n >= a && n >= b && n >= c) {
      cout << c + diff << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
