#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
pair<int, int> extgcd(int a, int b) {
  if (!b) return {1, 0};
  pair<int, int> p = extgcd(b, a % b);
  return {p.second, p.first - p.second * (a / b)};
}
int mod_inv(int a, int p) {
  int inv = extgcd(a, p).first;
  return inv;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, x, y, vx, vy;
  cin >> n >> m >> x >> y >> vx >> vy;
  if (vx == 0) {
    if (x != 0 && x != n) {
      cout << "-1\n";
      return 0;
    }
    if (vy < 0) {
      cout << x << " 0\n";
      return 0;
    } else {
      cout << x << " " << m << '\n';
      return 0;
    }
  } else if (vy == 0) {
    if (y != 0 && y != m) {
      cout << "-1\n";
      return 0;
    }
    if (vx < 0) {
      cout << "0 " << y << '\n';
      return 0;
    } else {
      cout << n << " " << y << '\n';
      return 0;
    }
  }
  int r1 = vx > 0 ? n - x : x, r2 = vy > 0 ? m - y : y, z = r2 - r1,
      g = gcd(n, m);
  if (z % g != 0) {
    cout << "-1\n";
    return 0;
  }
  z /= g;
  int nn = n / g, mm = m / g;
  long long p = (long long)z * mod_inv(nn, mm) % mm;
  p = (p % mm + mm) % mm;
  long long t = p * n + r1;
  t %= n * mm;
  x += vx * (t % (2 * n));
  if (x < 0)
    x = n;
  else if (x > n)
    x = 0;
  y += vy * (t % (2 * m));
  if (y < 0)
    y = m;
  else if (y > m)
    y = 0;
  cout << x << " " << y << '\n';
}
