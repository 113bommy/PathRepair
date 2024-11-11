#include <bits/stdc++.h>
using namespace std;
long long x, y, d;
void extEuclid(long long a, long long b) {
  if (b == 0) {
    x = 1;
    y = 0;
    d = a;
    return;
  }
  extEuclid(b, a % b);
  x = x - (a / b) * y;
  swap(x, y);
}
long long modInverse(long long a, long long m) {
  long long res;
  extEuclid(a, m);
  if (d != 1) {
    cout << "Inverse doesn't exist";
  } else {
    res = (x % m + m) % m;
    return res;
  }
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  extEuclid(a, b);
  if (c % d == 0) {
    a = x * (c / d);
    a *= -1;
    b = y * (c / d);
    b *= -1;
    cout << a << " " << b << endl;
  } else
    cout << -1 << endl;
}
