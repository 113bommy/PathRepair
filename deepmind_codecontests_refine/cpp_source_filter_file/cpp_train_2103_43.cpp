#include <bits/stdc++.h>
using namespace std;
const int MX = 500000 + 5;
const long long inf = 1e9;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q, a, b, c, d, k, x, y;
  cin >> q;
  while (q--) {
    cin >> a >> b >> c >> d >> k;
    x = a / c + ((a % c) != 0);
    y = b / d + ((b / d) != 0);
    if (x + y <= k)
      cout << x << ' ' << y << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
