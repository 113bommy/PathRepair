#include <bits/stdc++.h>
using namespace std;
int m, n, a;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int amax = max((a, b), max(c, d));
  if (a == amax) cout << a - b << " " << a - c << " " << a - d;
  if (b == amax) cout << b - a << " " << b - c << " " << b - d;
  if (c == amax) cout << c - a << " " << c - b << " " << c - d;
  if (d == amax) cout << d - a << " " << d - b << " " << d - c;
}
