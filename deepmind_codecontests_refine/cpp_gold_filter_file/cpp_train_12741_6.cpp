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
  if (ax < 0) ax = 0;
  if (ax > n - a) ax = n - a;
  ay = y - (b + 1) / 2;
  if (ay < 0) ay = 0;
  if (ay > m - b) ay = m - b;
  cout << ax << " " << ay << " " << ax + a << " " << ay + b << endl;
}
