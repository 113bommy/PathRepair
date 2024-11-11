#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    int mnx = -1e5, mny = -1e5, mxx = 1e5, mxy = 1e5;
    while (n--) {
      int x, y, a, b, c, d;
      cin >> x >> y >> a >> b >> c >> d;
      if (!a) mnx = max(mnx, x);
      if (!b) mny = max(mny, y);
      if (!c) mxx = min(mxx, x);
      if (!d) mxy = min(mxy, y);
    }
    if (mnx <= mxx && mny <= mxy) {
      cout << "1"
           << " " << mnx << " " << mny << "\n";
    } else {
      cout << "0"
           << "\n";
    }
  }
}
