#include <bits/stdc++.h>
using namespace std;
long long x, y, m, ans = 0, temp;
int main() {
  cin >> x >> y >> m;
  if (x > y) {
    temp = x;
    x = y;
    y = temp;
  }
  if (x >= m || y >= m)
    cout << "0\n";
  else if (x <= 0 && y <= 0) {
    cout << "-1\n";
  } else {
    if (x < 0 && y < m) {
      ans += (x * (-1)) / y;
      x += ans * y;
    }
    while ((x < m) && (y < m)) {
      if (x < y) {
        x = x + y;
      } else {
        y = x + y;
      }
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
