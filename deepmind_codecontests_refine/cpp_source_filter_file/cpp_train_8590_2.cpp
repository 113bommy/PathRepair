#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h, d;
  cin >> n >> d >> h;
  if (d > 2 * h || (d == 1 && n != 2)) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= h; ++i) cout << i << ' ' << i + 1 << '\n';
  int x = 1;
  for (int i = 1; i <= d - h; ++i) {
    int y = h + 1 + i;
    cout << x << ' ' << y << '\n';
    x = y;
  }
  for (int i = d + 2; i <= n; ++i) {
    cout << ((d == h) ? 2 : 1) << ' ' << i << '\n';
  }
  return 0;
}
