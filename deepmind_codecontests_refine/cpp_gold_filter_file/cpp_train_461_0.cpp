#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5 + 10;
int main() {
  long long c1, c2, x, y;
  cin >> c1 >> c2 >> x >> y;
  long long max1 = c1 + (c1 - 1) / (x - 1);
  long long max2 = c2 + (c2 - 1) / (y - 1);
  long long rpta = max(max1, max2);
  long long a2 = rpta / x - rpta / (x * y);
  long long a1 = rpta / y - rpta / (x * y);
  c1 = max(0LL, c1 - a1);
  c2 = max(0LL, c2 - a2);
  long long extra = min(c1, c2);
  long long ant = rpta;
  long long nue = rpta + extra;
  while (extra) {
    extra = (nue / (x * y)) - (ant / (x * y));
    ant = nue;
    nue += extra;
  }
  cout << nue << endl;
  return 0;
}
