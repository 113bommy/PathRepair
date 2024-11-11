#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int a = abs(x), b = abs(y);
  int ans1 = a + b, ans2 = a + b;
  if (a != x) ans1 *= -1;
  if (b != y) ans2 * -1;
  if (0 < ans2)
    cout << "0 " << ans1 << ' ' << ans2 << " 0";
  else
    cout << ans2 << " 0 0 " << ans2;
  return 0;
}
