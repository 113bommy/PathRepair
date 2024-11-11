#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c[1005], used[1005] = {0}, i, j;
  cin >> a >> b;
  for (i = 1; i <= b; i++) {
    int x, y, z, kol = 0;
    cin >> x >> y >> z;
    for (j = 1; j <= a; j++) {
      if (used[j] <= x) kol++;
    }
    if (kol >= y) {
      int ans = 0;
      for (j = 1; j <= a; j++) {
        if (y == 0)
          break;
        else if (used[j] < x) {
          ans += j;
          used[j] = x + z;
          y--;
        }
      }
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
