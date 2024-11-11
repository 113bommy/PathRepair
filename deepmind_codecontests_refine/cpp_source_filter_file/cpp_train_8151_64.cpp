#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int x = k * l / n;
  int y = c * d;
  int z = p / np;
  x /= n;
  y /= n;
  z /= n;
  int a = min(x, y);
  int b = min(a, z);
  cout << b;
  return 0;
}
