#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long x, y, n;
  cin >> x >> y >> n;
  long long li = -1, mi = -1;
  long long a, b;
  for (int j = 1; j <= n; ++j) {
    long long r = (j * x) % y;
    long long w1 = j * x - r;
    long long w2 = w1 + r;
    long long i1 = w1 / y;
    long long i2 = w2 / y;
    if (li == -1 || (li != -1 && abs(y * i1 - j * x) * mi < li * y * j) ||
        (li != -1 && abs(y * i1 - j * x) * mi == li * y * j && j < b) ||
        (li != -1 && abs(y * i1 - j * x) * mi == li * y * j && j == b &&
         i1 < a)) {
      li = abs(y * i1 - j * x);
      mi = y * j;
      a = i1;
      b = j;
    }
    if (li == -1 || (li != -1 && abs(y * i2 - j * x) * mi < li * y * j) ||
        (li != -1 && abs(y * i2 - j * x) * mi == li * y * j && j < b) ||
        (li != -1 && abs(y * i2 - j * x) * mi == li * y * j && j == b &&
         i2 < a)) {
      li = abs(y * i2 - j * x);
      mi = y * j;
      a = i2;
      b = j;
    }
  }
  cout << a << "/" << b;
  return 0;
}
