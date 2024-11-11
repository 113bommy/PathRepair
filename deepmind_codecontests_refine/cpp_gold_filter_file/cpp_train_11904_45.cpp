#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int S;
long double tern(long double low, long double high,
                 long double f(long double)) {
  for (int times = 0; times < (1000); times++) {
    long double a = (2 * low + high) / 3.;
    long double b = (low + 2 * high) / 3.;
    long double va = f(a);
    long double vb = f(b);
    if (va >= vb) high = b;
    if (va <= vb) low = a;
  }
  return low;
}
long double tempx;
long double f2(long double y) {
  long double x = tempx;
  long double z = S - (x + y);
  return a * log(x) + b * log(y) + c * log(z);
}
long double yy, zz;
long double best_given_x(long double x) {
  long double ans = -1.0 / 0.0;
  tempx = x;
  long double y = tern(0, S - x, f2);
  yy = y;
  zz = S - (x + y);
  return f2(y);
  return ans;
}
int main() {
  cin >> S >> a >> b >> c;
  long double xmax = tern(0, S, best_given_x);
  cout << fixed << setprecision(20) << xmax << " " << yy << " " << zz << endl;
}
