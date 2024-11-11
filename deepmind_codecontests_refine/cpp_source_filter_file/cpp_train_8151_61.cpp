#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np, a, b, e, x, y, z;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  a = (k * l) / n;
  b = c * d;
  e = p / np;
  x = min(a, min(b, e));
  cout << x / n << endl;
  return 0;
}
