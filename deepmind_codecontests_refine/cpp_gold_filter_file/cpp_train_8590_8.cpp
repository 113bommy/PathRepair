#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, d, h, r;
  cin >> n >> d >> h;
  if (2 * h < d || n > 2 && h == 1 && d == 1) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= h; ++i) {
    cout << i << ' ' << i + 1 << '\n';
  }
  r = h + 1;
  if (h < d) {
    cout << 1 << ' ' << h + 2 << '\n';
    for (int i = 1; i < d - h; ++i) {
      cout << h + 1 + i << ' ' << h + 2 + i << '\n';
    }
    r = d + 1;
  }
  for (int i = r + 1; i <= n; ++i) {
    cout << h << ' ' << i << '\n';
  }
}
