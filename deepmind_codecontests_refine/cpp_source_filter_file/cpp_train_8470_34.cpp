#include <bits/stdc++.h>
using namespace std;
int main() {
  long int a, b, c, d, i, y, x, x1, x2, x3;
  cin >> y;
  y = y + 1;
  for (i = y; i < 9000; i++) {
    x = i;
    a = x % 10;
    x = x / 10;
    b = x % 10;
    x = x / 10;
    c = x % 10;
    x = x / 10;
    d = x % 10;
    if ((a == b) || (b == c) || (c == d) || (d == a) || (a == c) || (b == d))
      continue;
    else
      cout << i;
    return 0;
  }
}
