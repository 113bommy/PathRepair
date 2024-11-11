#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, a, b, d = 1000000000;
int main() {
  cin >> n >> m >> i >> j >> a >> b;
  if ((i - a < 1 && i + a > n || j - b < 1 && j + b > m) &&
      (i != 1 && i != n || j != 1 && j != m)) {
    cout << "Poor Inna and pony!";
    return 0;
  }
  if ((i - 1) % a == 0 && (j - 1) % b == 0 &&
      ((i - 1) / a + (j - 1) / b) % 2 == 0)
    d = min(d, max((i - 1) / a, (j - 1) / b));
  if ((n - i) % a == 0 && (j - 1) % b == 0 &&
      ((n - i) / a + (j - 1) / b) % 2 == 0)
    d = min(d, max((n - i) / a, (j - 1) / b));
  if ((i - 1) % a == 0 && (m - j) % b == 0 &&
      ((i - 1) / a + (m - j) / b) % 2 == 0)
    d = min(d, max((i - 1) / a, (m - j) / b));
  if ((n - i) % a == 0 && (m - j) % b == 0 &&
      ((n - i) / a + (m - j) / b) % 2 == 0)
    d = min(d, max((n - i) / a, (m - j) / b));
  if (d == 1000000000)
    cout << "Poor Inna and pony!";
  else
    cout << d;
}
