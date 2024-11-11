#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll md = 1000000007;
ll exp(ll a, ll b) {
  ll r = 1ll;
  while (b > 0) {
    if (b & 1) {
      r = r * (a % md);
      r = (r + md) % md;
    }
    b >>= 1;
    a = (a % md) * (a % md);
    a = (a + md) % md;
  }
  return (r + md) % md;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll Min(ll a, ll b) {
  if (a < b) return a;
  return b;
}
ll Max(ll a, ll b) {
  if (a > b) return a;
  return b;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, b;
  cin >> a >> b;
  for (long long x1 = 1; x1 <= a; ++x1) {
    long long d = a * a - x1 * x1, y1 = sqrt(d);
    if (y1 * y1 == d && y1 != 0) {
      long long x2 = (b * y1) / a;
      long long d2 = b * b - x2 * x2, y2 = -(sqrt(d2));
      if (y2 * y2 == d2 && a * x2 == b * y1 && y2 != 0) {
        if (x1 != x2 || y1 != y2) {
          cout << "YES" << '\n';
          cout << "0 0\n";
          cout << x1 << " " << y1 << '\n';
          cout << x2 << " " << y2;
          return 0;
        }
      }
    }
  }
  cout << "NO";
  cout << '\n';
  return 0;
}
