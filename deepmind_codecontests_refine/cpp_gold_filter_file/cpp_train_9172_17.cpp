#include <bits/stdc++.h>
using namespace std;
long double xa[104] = {0};
long double ya[104] = {0};
long double za[104] = {0};
long long int n;
long double sum(long double x, long double y, long double z) {
  return x * x + y * y + z * z;
}
int main() {
  cin >> n;
  for (long long int i = 1; i <= n; i++) {
    cin >> xa[i] >> ya[i] >> za[i];
    xa[0] += xa[i];
    ya[0] += ya[i];
    za[0] += za[i];
  }
  long double X = xa[0] / n;
  long double Y = xa[0] / n;
  long double Z = xa[0] / n;
  long double p = 0.1;
  for (long long int tt = 1; tt <= 30000; tt++) {
    long long int k = 1;
    long double ans = sum(xa[1] - X, ya[1] - Y, za[1] - Z);
    for (int i = 2; i <= n; i++) {
      long double e = sum(xa[i] - X, ya[i] - Y, za[i] - Z);
      if (ans < e) {
        k = i;
        ans = e;
      }
    }
    X += (xa[k] - X) * p;
    Y += (ya[k] - Y) * p;
    Z += (za[k] - Z) * p;
    p *= .999;
  }
  cout << fixed << setprecision(7) << X << " " << Y << " " << Z << endl;
}
