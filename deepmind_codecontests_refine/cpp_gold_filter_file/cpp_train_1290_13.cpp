#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long x, y, m;
  cin >> x >> y >> m;
  long long sum = 0, k = 0, l = 0;
  if (x >= m || y >= m) {
    cout << "0"
         << "\n";
    return 0;
  } else if (x + y <= x && x + y <= y) {
    cout << "-1"
         << "\n";
    return 0;
  } else {
    if (x < 0 && y > 0) {
      sum = ceil((double)-x / y);
      x += sum * y;
    } else if (x > 0 && y < 0) {
      sum = ceil((double)-y / x);
      y += sum * x;
    }
    while (k < m) {
      k = x + y;
      if (x < y)
        x = k;
      else
        y = k;
      sum++;
    }
    cout << sum << "\n";
  }
  return 0;
}
