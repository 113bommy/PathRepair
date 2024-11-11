#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, m, res = 0;
  cin >> x >> y >> m;
  if (x >= m || y >= m) {
    cout << 0 << endl;
    return 0;
  }
  if (x <= 0 && y <= 0) {
    cout << -1 << endl;
    return 0;
  }
  if (x > y) swap(x, y);
  if (x < 0) {
    res = -x / y;
    x -= (x / y);
  }
  while (x < m && y < m) {
    res++;
    if (x < y)
      x = x + y;
    else
      y = x + y;
  }
  cout << res << endl;
  return 0;
}
