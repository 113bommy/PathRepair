#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x1, x2, y1, y2, n1, m, ans = 0, n2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1 += 1e9 + 2;
  x2 += 1e9 + 2;
  y1 += 1e9 + 2;
  y2 += 1e9 + 2;
  if (x1 % 2) {
    n1 = (y2 + 1) / 2 - (y1 - 1) / 2;
    n2 = y2 / 2 - (y1) / 2;
  } else {
    n1 = (y2 + 1) / 2 - (y1 - 1) / 2;
    n2 = y2 / 2 - (y1) / 2;
  }
  m = x2 - x1 + 1;
  ans = (n1 + n2) * (m / 2);
  if (m % 2) ans += n1;
  cout << ans;
}
