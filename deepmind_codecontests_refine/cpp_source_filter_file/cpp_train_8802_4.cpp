#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long m, n, i, j, k = 0, l, t, b, d, second;
  cin >> b >> d >> second;
  long long var;
  m = max(b, (max(d, second)));
  if (b == d && d == second)
    k = 0;
  else {
    if (second == m) {
      k = 2 * second - b - d;
    } else if (b == m) {
      if (d == b)
        k = b - 1 - second;
      else if (second == b)
        k = b - d;
      else
        k = 2 * b - 2 - second - d;
    } else if (d == m) {
      if (d == b)
        k = d - 1 - second;
      else if (second == d)
        k = d - b;
      else
        k = d - second - 1 + d - b;
    }
    if (b == m) {
      k = min(k, 2 * b - second - d);
    } else if (d == m) {
      if (second == m)
        k = min(k, d - b - 1);
      else
        k = min(d - 1 - second + d - b - 1, k);
    } else if (second == m) {
      k = min(k, second - d + second - b - 1);
    }
    if (b == m) {
      if (d == b)
        k = min(k, b - second);
      else
        k = min(k, b - second + b - d - 1);
    } else if (d == m) {
      k = min(k, d - b + d - second);
    } else if (second == m) {
      k = min(k, 2 * second - b - d);
    }
  }
  cout << k << "\n";
  return 0;
}
