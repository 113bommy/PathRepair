#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k > m + n - 2) {
    cout << -1 << endl;
    return 0;
  }
  int x, y, a, b;
  x = min(k + 1, n);
  y = k + 2 - x;
  a = (n / x) * (m / y);
  y = min(k + 1, m);
  x = k + 2 - y;
  b = (n / x) * (m / y);
  cout << max(a, b) << endl;
  return 0;
}
