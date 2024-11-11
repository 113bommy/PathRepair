#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, x, y, ax, ay;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  cin >> n >> m >> x >> y >> a >> b;
  int c = gcd(a, b);
  a /= c;
  b /= c;
  int d = min(n / a, m / b);
  a *= d;
  b *= d;
  ax = x - (a + 1) / 2;
  if (x < 0) x = 0;
  if (x > n - a) x = n - a;
  ay = y - (b + 1) / 2;
  if (y < 0) y = 0;
  if (y > m - b) y = m - b;
  cout << ax << " " << ay << " " << ax + a << " " << ay + b << endl;
}
