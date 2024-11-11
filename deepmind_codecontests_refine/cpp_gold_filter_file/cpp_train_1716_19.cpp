#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
long long a, b;
int main() {
  long long c, x, y, x1, y1;
  cin >> c >> x >> y >> x1 >> y1;
  long long res = 0;
  if (x1 < y1) {
    swap(x1, y1);
    swap(x, y);
  }
  if (c / x1 < N - 5) {
    for (int i = (int)0; i < (int)c / x1 + 1; i++) {
      a = i;
      b = (c - a * x1) / y1;
      if (a >= 0 && b >= 0 && a * x1 + b * y1 <= c)
        res = max(res, a * x + b * y);
    }
  } else {
    for (int i = (int)0; i < (int)max(x1, y1) + 1; i++) {
      a = i;
      b = (c - a * x1) / y1;
      if (a >= 0 && b >= 0 && a * x1 + b * y1 <= c)
        res = max(res, a * x + b * y);
    }
    for (int i = c / x1, mm = c / x1 - max(x1, y1) - 1; i >= max(0, mm); i--) {
      a = i;
      b = (c - a * x1) / y1;
      if (a >= 0 && b >= 0 && a * x1 + b * y1 <= c)
        res = max(res, a * x + b * y);
    }
  }
  cout << res;
}
