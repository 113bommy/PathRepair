#include <bits/stdc++.h>
using namespace std;
long long x, y, m, sum, unk;
long long func(long long a, long long b, long long c) {
  while (1) {
    if (a >= c || b >= c) {
      cout << sum;
      break;
    } else if (a >= b)
      b = a + b;
    else
      a = a + b;
    sum++;
  }
  return sum;
}
int main() {
  cin >> x >> y >> m;
  if (x == m || y == m) {
    cout << 0;
    return 0;
  }
  if ((x == 0 && y < 0) || (x < 0 && y == 0) || (x < 0 && y < 0 && x + y < m) ||
      (x >= 0 && y >= 0 && (x > m || y > m)) || (x <= 0 && y <= 0 && m > 0)) {
    cout << "-1";
    return 0;
  } else {
    if (x >= 0 && y >= 0)
      func(x, y, m);
    else {
      if (x < 0 && y >= 0) {
        unk = abs(x % y);
        long long z = x;
        x += unk;
        sum = abs(x / y);
        if (z % y == 0)
          x = 0;
        else {
          x = z % y + y;
          sum++;
        }
        func(x, y, m);
      } else if (y < 0 && x >= 0) {
        unk = abs(y % x);
        long long z = y;
        y += unk;
        sum = abs(y / x);
        if (z % x == 0)
          y = 0;
        else {
          y = z % x + x;
          sum++;
        }
        func(x, y, m);
      } else
        func(abs(x), abs(y), abs(m));
    }
  }
}
