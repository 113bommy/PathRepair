#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, a, x, b, res;
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    int z = 0;
    cin >> n >> x >> a >> b;
    if (a > b) swap(a, b);
    if (a - x >= 1)
      res = b - a + x;
    else {
      z = a - 1;
      if (b + x - z <= n)
        res = b + x - z - 1;
      else
        res = n - 1;
    }
    cout << res << "\n";
  }
  return 0;
}
