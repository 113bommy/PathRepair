#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, m, x, y;
  cin >> n >> d >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if ((y <= -x + 2 * n - d) && (y >= -x + d) && (y <= x + d) &&
        (y >= x - d)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
