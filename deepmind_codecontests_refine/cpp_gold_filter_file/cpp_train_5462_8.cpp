#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long a1 = a, b1 = b, c1 = c, d1 = d;
  long long c12 = 0, c13 = 0, c22 = 0, c23 = 0;
  long long ans = 0;
  while (a1 % 3 == 0 && a1) a1 /= 3, c13++;
  while (b1 % 3 == 0 && b1) b1 /= 3, c13++;
  while (c1 % 3 == 0 && c1) c1 /= 3, c23++;
  while (d1 % 3 == 0 && d1) d1 /= 3, c23++;
  while (c13 > c23 && a % 3 == 0 && a) a = a * 2 / 3, c13--, ans++;
  while (c13 > c23 && b % 3 == 0 && b) b = b * 2 / 3, c13--, ans++;
  while (c13 < c23 && c % 3 == 0 && c) c = c * 2 / 3, c23--, ans++;
  while (c13 < c23 && d % 3 == 0 && d) d = d * 2 / 3, c23--, ans++;
  a1 = a, b1 = b, c1 = c, d1 = d;
  while (d1 % 2 == 0 && d1) d1 /= 2, c22++;
  while (b1 % 2 == 0 && b1) b1 /= 2, c12++;
  while (c1 % 2 == 0 && c1) c1 /= 2, c22++;
  while (a1 % 2 == 0 && a1) a1 /= 2, c12++;
  while (c12 > c22 && a % 2 == 0 && a) a /= 2, c12--, ans++;
  while (c12 > c22 && b % 2 == 0 && b) b /= 2, c12--, ans++;
  while (c12 < c22 && c % 2 == 0 && c) c /= 2, c22--, ans++;
  while (c12 < c22 && d % 2 == 0 && d) d /= 2, c22--, ans++;
  if (a * b != c * d) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  cout << a << ' ' << b << endl;
  cout << c << ' ' << d << endl;
  return 0;
}
