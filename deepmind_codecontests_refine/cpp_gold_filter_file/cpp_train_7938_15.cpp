#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y;
  cin >> n >> m >> y >> x;
  cout << y << ' ' << x << '\n';
  for (int i = 1; i <= m; ++i) {
    if (i == x) continue;
    cout << y << ' ' << i << '\n';
  }
  for (int i = m; i >= 1; --i) {
    for (int j = 1; j <= n; ++j) {
      if (j == y) continue;
      cout << j << ' ' << i << '\n';
    }
    if (--i < 1) break;
    for (int j = n; j >= 1; --j) {
      if (j == y) continue;
      cout << j << ' ' << i << '\n';
    }
  }
}
