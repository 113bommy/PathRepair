#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int a, b, c, d, i, j, n, m, k;
long double best;
long long sum, by1, by2;
int main() {
  int t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if (t0 == t1 && t0 == t2) {
    cout << x1 << " " << x2 << endl;
    exit(0);
  }
  if (t0 == t2) {
    cout << 0 << " " << x2 << endl;
    exit(0);
  }
  best = 1e100;
  sum = -1;
  for (int y1 = 0; y1 <= x1; ++y1) {
    long long y2 = (long long)y1 * (t0 - t1) / (t2 - t0);
    if (y2 > x2) y2 = x2;
    if (!y1) y2 = 1;
    while (y2 < x2 &&
           (long long)t1 * y1 + (long long)t2 * y2 < (long long)t0 * (y1 + y2))
      ++y2;
    if (y2 <= x2 &&
        (long long)t1 * y1 + (long long)t2 * y2 >= (long long)t0 * (y1 + y2)) {
      long double cur = (long double)t1 * y1 + (long double)t2 * y2;
      cur /= y1 + y2;
      if (cur + 1e-9 < best || (abs(cur - best) < 1e-9 && y1 + y2 > sum)) {
        best = cur;
        sum = y1 + y2;
        by1 = y1;
        by2 = y2;
      }
    }
  }
  cout << by1 << " " << by2 << endl;
}
