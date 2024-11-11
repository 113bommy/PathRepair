#include <bits/stdc++.h>
using namespace std;
long long Extended_gcd(long long a, long long b, long long &x, long long &y) {
  if (a < 0) {
    long long r = Extended_gcd(-a, b, x, y);
    x *= -1;
    return r;
  }
  if (b < 0) {
    long long r = Extended_gcd(a, -b, x, y);
    y *= -1;
    return r;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = Extended_gcd(b, a % b, y, x);
  y -= (a / b) * x;
  return g;
}
long long Linear_Diophantine(long long a, long long b, long long c,
                             long long &x, long long &y, long long &found) {
  long long g = Extended_gcd(a, b, x, y);
  if (found = c % g == 0) x *= c / g, y *= c / g;
  return g;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long x, y, a, b, c, t;
  cin >> a >> b >> c;
  Linear_Diophantine(a, b, c, x, y, t);
  if (t)
    cout << x << " " << y << endl;
  else
    cout << -1;
  return 0;
}
