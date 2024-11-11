#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long g = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
void solveDiophantine(long long a, long long b, long long c, long long &x,
                      long long &y) {
  long long g = extended_gcd(a, b, x, y);
  if (c % g != 0) {
    puts("-1");
    exit(0);
  }
  c /= g;
  x = x * c;
  y = y * c;
}
long long a, b, c;
long long x, y;
long long g;
int main() {
  cin >> a >> b >> c;
  c = -c;
  if (a == 0 && c % b == 0) {
    cout << 0 << " " << c / b << endl;
    return 0;
  } else if (b == 0 && c % a == 0) {
    cout << c / a << " " << 0 << endl;
    return 0;
  }
  solveDiophantine(a, b, c, x, y);
  g = gcd(a, b);
  long long add = b / g;
  long long num = 0;
  if (add < 0)
    num = (long long)floor(1.0 * -x / add);
  else
    num = (long long)ceil(1.0 * -x / add);
  x = x + b / g * num;
  y = y - a / g * num;
  cout << x << " " << y;
  return 0;
}
