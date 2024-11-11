#include <bits/stdc++.h>
using namespace std;
int main() {
  map<long double, long double> sine;
  for (long long i = 100; i >= 3; i--) {
    long double k = 360.0 / (long double)(i * 2);
    sine[k] = sin(k * 3.14159265 / 180);
  }
  long double N, r, R;
  cin >> N >> r;
  long double angle = sine[360.0 / (2 * N)];
  r = r * angle;
  R = r / (1.0 - angle);
  cout << setprecision(9) << endl;
  cout << (long double)R << endl;
  ;
}
