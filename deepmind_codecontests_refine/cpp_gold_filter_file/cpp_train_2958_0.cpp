#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n, m, mx, mn, mn2;
  cin >> n >> m >> a;
  mx = a;
  mn = a;
  for (int i = 1; i < n; i++) {
    cin >> a;
    mx = max(a, mx);
    mn = min(a, mn);
  }
  cin >> a;
  mn2 = a;
  for (int i = 1; i < m; i++) {
    cin >> a;
    mn2 = min(a, mn2);
  }
  if (mx >= mn2) {
    cout << -1 << endl;
    return 0;
  }
  bool ok = false;
  for (int i = mx; i < mn2; i++) {
    if (2 * mn <= i) {
      cout << i << endl;
      ok = true;
      break;
    }
  }
  if (!ok) cout << -1 << endl;
}
