#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
bool find_any_solution(long long a, long long b, long long c, long long &x0,
                       long long &y0, long long &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  long long x0, y0;
  long long g = gcd(a, b);
  if (find_any_solution(a, b, abs(c), x0, y0, g)) {
    if (c < 0)
      cout << x0 << " " << y0;
    else
      cout << -x0 << " " << -y0;
  } else
    cout << -1;
}
