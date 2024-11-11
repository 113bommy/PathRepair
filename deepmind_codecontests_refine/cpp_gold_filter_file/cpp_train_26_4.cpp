#include <bits/stdc++.h>
using namespace std;
int main() {
  int r1, r2, c1, c2, d1, d2, a, b, c, d;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  a = d1 - 1;
  d = 1;
  while (a > 0) {
    b = r1 - a;
    c = c1 - a;
    if ((r1 == a + b) && (r2 == c + d) && (c1 == a + c) && (c2 == b + d) &&
        (d2 == b + c) && (a != b) && (a != c) && (a != d) && (b != c) &&
        (b != d) && (c != d) && (a < 10) && (b < 10) && (c < 10) & (d < 10))
      break;
    a--;
    d++;
  }
  if ((a == 0) || (b == 0) || (c == 0) || (d == 0)) {
    cout << -1 << endl;
    return 0;
  }
  cout << a << " " << b << endl;
  cout << c << " " << d << endl;
  return 0;
}
