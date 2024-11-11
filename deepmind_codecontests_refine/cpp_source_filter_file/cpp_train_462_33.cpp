#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long r, x, y, a, b;
  cin >> r >> x >> y >> a >> b;
  long long d = ceil(sqrt(abs(x - a) * abs(x - a) + abs(y - b) * abs(y - b)));
  if (d % (2 * r) == 0)
    cout << d / (2 * r);
  else
    cout << (d / 2 * r) + 1;
  return 0;
}
