#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, ans = 0;
  cin >> x >> y;
  if (x <= 3) ans += 100000 * (4 - x);
  if (y <= 3) ans += 100000 * (4 - x);
  if (ans == 600000) ans += 400000;
  cout << ans << endl;
}
