#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y;
  y = z - y * (a / b);
  return d;
}
int main(int argc, char const* argv[]) {
  cin >> a >> b >> c;
  long long x, y;
  long long d = exgcd(a, b, x, y);
  if (c % d) {
    cout << -1 << endl;
  } else {
    x = c / d * x;
    y = c / d * y;
    cout << x << " " << y << endl;
  }
  return 0;
}
