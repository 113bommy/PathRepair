#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const long long mod1 = 998244353;
const long long mod2 = 1000000007;
long long pow(int a, int b) {
  if (b == 0 || a == 1) return 1;
  if (b % 2 == 0) {
    long long k = pow(a, b / 2);
    return (k * k);
  } else {
    long long k = pow(a, b / 2);
    return k * k * a;
  }
}
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
int prime(int p) {
  for (int i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return 0;
  }
  return 1;
}
long long sqr(long long i) { return i * i; }
double pi = 3.1415926;
using namespace std;
double ang(double x, double y) {
  if (x == 0 && y > 0) return 90;
  if (x > 0 && y == 0) return 0;
  if (x < 0 && y == 0) return 180;
  if (x == 0 && y < 0) return 270;
  if (x > 0 && y > 0) return atan(y / x) / pi * 180.0;
  if (x > 0 && y < 0) return 270 + atan(-y / x) / pi * 180.0;
  if (x < 0 && y < 0) return 180 + atan(y / x) / pi * 180.0;
  if (x < 0 && y > 0) return 90 + atan(-x / y) / pi * 180.0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int a;
  cin >> a;
  pair<int, int> m[a];
  vector<double> angle;
  for (int i = 0; i < a; i++) {
    cin >> m[i].first >> m[i].second;
    angle.push_back(ang(m[i].first, m[i].second));
  }
  sort(angle.begin(), angle.end());
  if (a == 2) {
    cout << min(abs(angle[0] - angle[1]), 360.0 - abs(angle[0] - angle[1]));
    return 0;
  }
  double min1 = 100000;
  for (int i = 1; i < a; i++) min1 = min(min1, 360.0 - angle[i] + angle[i - 1]);
  min1 = min(min1, 360 - (angle[0] + 360 - angle[a - 1]));
  cout << min1;
  return 0;
}
