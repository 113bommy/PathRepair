#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535;
long double convert(long double n) {
  long double val = (n * PI) / 180;
  return val;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int oneSide = (n / 2) - 1;
    n = n * 2;
    long long int sumOfAngles = (n - 2) * 180;
    long double singleAngle = sumOfAngles / ((long double)n);
    long double sub = singleAngle - 180;
    long double angle = singleAngle - 90;
    long double ans = 0;
    while (angle > 0) {
      ans = ans + sin(convert(angle));
      angle = angle + sub;
    }
    cout << fixed << setprecision(10) << (ans * 2) + 1 << endl;
  }
  return 0;
}
