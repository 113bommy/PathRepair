#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    int l, m, n;
    cin >> l >> m >> n;
    int q = min(z, m);
    y -= q;
    z -= q;
    int u = 0;
    if ((x + z) < n) u = n - (x + z);
    cout << 2 * q - u << endl;
  }
  return 0;
}
