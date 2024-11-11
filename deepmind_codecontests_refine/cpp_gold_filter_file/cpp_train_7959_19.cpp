#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a1 = -2e9, a2 = 2e9, a3 = -2e9, a4 = 2e9;
  int n, m, x, y;
  cin >> n >> m;
  cin >> n;
  while (n--)
    cin >> x >> y, a1 = max(a1, x + y), a2 = min(a2, x + y),
                   a3 = max(a3, x - y), a4 = min(a4, x - y);
  cin >> m;
  int ans = 2e9, ind, p = 0;
  while (m--) {
    cin >> x >> y;
    ++p;
    if (ans > max(max(abs(x + y - a1), abs(x + y - a2)),
                  max(abs(x - y - a3), abs(x - y - a4))))
      ans = max(max(abs(x + y - a1), abs(x + y - a2)),
                max(abs(x - y - a3), abs(x - y - a4))),
      ind = p;
  }
  return cout << ans << '\n' << ind << '\n', 0;
}
