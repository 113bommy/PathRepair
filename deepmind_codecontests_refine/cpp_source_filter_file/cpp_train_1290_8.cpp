#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
int main() {
  long long x, y, m;
  cin >> x >> y >> m;
  if (x == m || y == m) {
    cout << 0 << endl;
    return 0;
  }
  if (x <= 0 && y <= 0) {
    cout << -1 << endl;
    return 0;
  }
  long long count = 0;
  if (x > y) swap(x, y);
  if (x < 0) {
    count += (-x) / y;
    x += count * y;
  }
  while (true) {
    if (max(x, y) >= m) break;
    count += 1;
    if (x <= y)
      x = x + y;
    else
      y = x + y;
  }
  cout << count << endl;
}
