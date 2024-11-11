#include <bits/stdc++.h>
using namespace std;
long long gcd(long long b, long long y) { return b > 0 ? gcd(y % b, b) : y; }
long long lcm(long long b, long long y) { return b * y / gcd(b, y); }
double dis(double x1, double x2, double y1, double y2) {
  double ans = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(ans);
}
double random(double start, double en) {
  return start + (en - start) * rand() / (RAND_MAX + 1.0);
}
long long k, mod;
struct MX {
  long long m[15][15];
  MX operator*(const MX& a) const {
    MX t;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        t.m[i][j] = 0;
        for (int kk = 0; kk < 10; kk++) {
          t.m[i][j] += m[i][kk] * a.m[kk][j] % mod;
          t.m[i][j] % mod;
        }
      }
    }
    return t;
  }
};
int main() {
  int a[5];
  while (cin >> a[0] >> a[1] >> a[2]) {
    sort(a, a + 3);
    cout << a[2] - a[1] + a[3] - a[2] << endl;
  }
}
