#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a += inf;
  b += inf;
  c += inf;
  d += inf;
  int x, y;
  cin >> x >> y;
  if ((a % x == c % x) && (b % y == d % y) &&
      ((a - c) / x) % 2 == ((b - d) / y) % 2)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
