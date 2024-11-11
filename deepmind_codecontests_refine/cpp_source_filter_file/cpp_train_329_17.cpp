#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p, w, d, y, z, pp;
  cin >> n >> p >> d >> w;
  for (y = 0; y <= d; y++) {
    long long kk = y * d;
    long long pp = p - kk;
    long long rem = pp % d;
    long long x = pp / d;
    if (rem == 0) {
      if (x >= 0 and x + y <= n) {
        cout << x << " " << y << " " << n - (x + y) << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
