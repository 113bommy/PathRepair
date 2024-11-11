#include <bits/stdc++.h>
using namespace std;
long long x, y, m;
int q;
int main() {
  cin >> x >> y >> m;
  if (x >= m || y >= m) {
    cout << "0";
  } else if (x <= 0 && y <= 0) {
    cout << "-1";
  } else {
    long long ans = 0;
    if (x > y) {
      long long mem = y;
      y = x;
      x = mem;
    }
    while (true) {
      long long mem = y;
      ans += (y - x + y) / y;
      y = x + ((y - x + y) / y) * y;
      x = mem;
      if (y >= m) {
        cout << ans;
        break;
      }
    }
  }
  return 0;
}
