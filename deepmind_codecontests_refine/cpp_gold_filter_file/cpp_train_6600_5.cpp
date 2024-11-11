#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a * d > b * c) {
    long long int g = gcd(fabs(a * d - b * c), a * d);
    cout << (a * d - b * c) / g << '/' << (a * d) / g;
  } else {
    long long int g = gcd(fabs(b * c - a * d), c * b);
    cout << fabs(b * c - a * d) / g << '/' << (c * b) / g;
  }
}
