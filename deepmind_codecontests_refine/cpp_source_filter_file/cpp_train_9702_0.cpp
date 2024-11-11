#include <bits/stdc++.h>
using namespace std;
long long mydiv(long long a, long long b) {
  if (a % b && a < 0)
    return a / b - 1;
  else
    return a / b;
}
int main() {
  for (int a, b, x1, y1, x2, y2;
       cin >> a >> b >> x1 >> y1 >> x2 >> y2 && a | b;) {
    long long res1 = abs(mydiv(x2 + y2, 2 * a) + mydiv(x1 + y1, 2 * a));
    long long res2 = abs(mydiv(x2 - y2, 2 * b) + mydiv(x1 - y1, 2 * b));
    cout << max(res1, res2) << endl;
  }
  return 0;
}
