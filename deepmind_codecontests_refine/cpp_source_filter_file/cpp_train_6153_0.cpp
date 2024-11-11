#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d, m;
  cin >> n >> d >> m;
  int lim1 = min(n - d, d), lim2 = max(n - d, d);
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x < lim1) {
      if (y < d - x || y > d + x)
        cout << "NO\n";
      else
        cout << "YES\n";
    } else if (x > lim2) {
      if (y > 2 * n - d - x || y < x - d)
        cout << "NO\n";
      else
        cout << "YES\n";
    } else if (x > lim1 && x < lim2) {
      if (y < abs(x - d) || y > 2 * lim1 + abs(x - d))
        cout << "NO\n";
      else
        cout << "YES\n";
    } else
      cout << "YES\n";
  }
  return 0;
}
