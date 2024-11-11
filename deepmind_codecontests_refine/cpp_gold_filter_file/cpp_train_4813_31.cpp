#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long res = 1e9, xx = 0, yy = 0, zz = 0;
    for (long long i = 1; i <= 1e4; i++) {
      for (long long k = 1; i * k <= 2e4; k++) {
        for (long long z = 1; z * i * k <= 2e4; z++) {
          long long q = i, w = i * k, r = z * i * k;
          if (res > abs(a - q) + abs(b - w) + abs(c - r)) {
            res = abs(a - q) + abs(b - w) + abs(c - r);
            xx = q, yy = w, zz = r;
          }
        }
      }
    }
    cout << res << "\n";
    cout << xx << " " << yy << " " << zz << "\n";
  }
}
