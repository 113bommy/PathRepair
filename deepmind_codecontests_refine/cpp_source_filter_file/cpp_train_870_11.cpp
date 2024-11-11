#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int m;
    cin >> m;
    while (m--) {
      int x, y;
      cin >> x >> y;
      if (x > n) continue;
      a[x - 1] += y - 1;
      a[x + 1] += a[x] - y;
      a[x] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i] << '\n';
    }
  }
  return 0;
}
