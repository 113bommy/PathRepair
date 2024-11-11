#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, m;
    cin >> n >> x >> m;
    int l = n + 1, r = -1;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      if ((x >= l && x <= r) || (x >= a && x <= b)) {
        if (a < l && (b >= l || l > n)) l = a;
        if (b > r && (a <= r || r < 0)) r = b;
      }
    }
    if (x >= l && x <= r)
      cout << r - l + 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
