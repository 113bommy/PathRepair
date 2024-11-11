#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
const double pie = 3.1415926535;
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else {
    if (y % 2 == 0)
      return power(x * x, y / 2);
    else
      return x * power(x * x, (y - 1) / 2);
  }
}
long long mod_power(long long x, long long y, long long m) {
  long long r = 1;
  x = x % m;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) r = (r * x) % m;
    y = y / 2;
    x = (x * x) % m;
  }
  return r;
}
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
vector<long long> extended_Euclid(long long a, long long b) {
  vector<long long> v(3);
  if (b == 0) {
    v[0] = a;
    v[1] = 1;
    v[2] = 0;
    return v;
  } else {
    vector<long long> v1 = extended_Euclid(b, a % b);
    v[0] = v1[0];
    v[1] = v1[2];
    v[2] = v1[1] - (a / b) * v1[2];
    return v;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TESTS = 1;
  while (TESTS--) {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long ans = 0;
    if (e >= f) {
      ans += min(a, d) * e;
      e = 0;
      d = d - e;
      if (d <= 0) d = 0;
      long long x = min(b, c);
      ans += min(d, x) * f;
    } else {
      long long x = min(b, c);
      ans += min(d, x) * f;
      d = d - x;
      if (d <= 0) d = 0;
      ans += min(d, a) * e;
    }
    cout << ans << endl;
  }
}
