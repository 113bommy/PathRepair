#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long x = 0, y = 0;
  long long k = gcd(a, b, x, y);
  if (c % k != 0) {
    cout << -1;
  } else {
    long long t = -c / k;
    cout << t * x << ' ' << t * y;
  }
}
