#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int out, res;
  int a = k * l;
  int b = a / nl;
  int x = c * d;
  int y = p / np;
  out = min(b, x);
  res = min(out, y);
  cout << res / n;
  return 0;
}
