#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, d, t;
  cin >> k >> d >> t;
  long double at = (long double)k;
  long double a = at / t;
  long double bt;
  if ((long double)k / (long double)d == (long long)k / (long long)d) {
    bt = (d * ((long double)(k / d)) - k);
  } else {
    bt = (d * ((long double)(k / d) + 1) - k);
  }
  long double b = bt / (2 * t);
  long double ct = at + bt;
  long double c = a + b;
  long long num = (1 / c);
  long double build = (long double)num * c;
  long double tot = num * ct;
  if (1 - build > a) {
    build += a;
    tot += at;
    tot += bt * ((1 - build) / b);
  } else if (1 - build > 0) {
    tot += at * ((1 - build) / a);
  }
  cout << setprecision(10) << tot;
  return 0;
}
