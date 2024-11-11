#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a -= c;
  b -= d;
  int x, y;
  cin >> x >> y;
  if (a % x == 0 && b % y == 0 && (abs(a / x) % 2) == (abs(b / y) % 2))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
