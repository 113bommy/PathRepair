#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
int n;
long long t0, t1, x0, x1, t;
long long r0, r1;
double res;
bool More(double a, double b) { return ((a - b) > (1E-13)); }
bool Eq(double a, double b) { return (fabs(a - b) <= (1E-13)); }
bool Less(double a, double b) { return ((b - a) > (1E-13)); }
int main() {
  cin >> t0 >> t1 >> x0 >> x1 >> t;
  res = 1000000000000000000.0;
  r0 = -1;
  r1 = -1;
  for (int(i) = (0); (i) < (x0 + 1); ++(i)) {
    long long d0 = t0 * i - t * i;
    long long d1 = t - t1;
    long long p;
    if (d1 == 0)
      p = x1;
    else
      p = d0 / d1;
    for (int(d) = (-2); (d) < (3); ++(d)) {
      long long e = p + d;
      if (e < 0) continue;
      if (e > x1) continue;
      double q = ((long long)i * t0 + e * t1 + 0.0) / ((long long)i + e + 0.0);
      if (Less(q, t)) continue;
      if (Less(q - t, res) ||
          (Eq(q - t, res) && ((long long)i + e > r0 + r1))) {
        res = q - t;
        r0 = i;
        r1 = e;
      }
    }
  }
  if (t == t1) {
  }
  cout << r0 << ' ' << r1 << endl;
  return 0;
}
