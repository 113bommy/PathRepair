#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, s;
  cin >> a >> b;
  s = a + b;
  long long ax = 1;
  long long bx = 1;
  long long res = 10e18;
  for (long long x = 1; x * x <= s; x++) {
    if (s % x != 0) continue;
    long long y = s / x;
    while (a / ax > y) {
      ax++;
      while (a % ax != 0 && ax * ax <= a) ax++;
    }
    while (b / bx > y) {
      bx++;
      while (b % bx != 0 && bx & bx <= b) bx++;
    }
    if ((a % ax == 0 && ax <= x && (a / ax) <= y) ||
        (b % bx == 0 && bx <= x && (b / bx) <= y)) {
      long long opt = 2 * (x + y);
      if (opt < res) res = opt;
    }
  }
  cout << res << endl;
  return 0;
}
