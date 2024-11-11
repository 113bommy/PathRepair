#include <bits/stdc++.h>
using namespace std;
const long long MX = 2e5 + 1;
const long long MOD = 1000000007;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long long minx = -500000, miny = -500000, maxx = 500000, maxy = 500000;
    for (long long i = 0; i < n; i++) {
      long long x, y, f1, f2, f3, f4;
      cin >> x >> y >> f1 >> f2 >> f3 >> f4;
      if (f1 == 0) {
        minx = max(minx, x);
      }
      if (f2 == 0) {
        maxy = min(maxy, y);
      }
      if (f3 == 0) {
        maxx = min(maxx, x);
      }
      if (f1 == 0) {
        miny = max(miny, y);
      }
    }
    if (miny <= maxy && minx <= maxx) {
      cout << "1 " << minx << " " << miny << "\n";
    } else {
      cout << "0\n";
    }
  }
}
