#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p, w, d, y, z;
  cin >> n >> p >> w >> d;
  for (y = 0; y <= w; y++) {
    long long kk = y * d;
    long long pp = p - kk;
    if (pp % w == 0) {
      long long x = pp / w;
      if (x >= 0 and x + y <= n) {
        cout << x << " " << y << " " << n - (x + y) << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
