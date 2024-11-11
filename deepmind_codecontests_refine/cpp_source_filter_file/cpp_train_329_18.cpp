#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)1e18 + 10;
const long long int MAX = 200005;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, p, w, d, x, y, z, t, f = 0;
  cin >> n >> p >> w >> d;
  long long int win = (p / w);
  long long int draw = (p / d);
  long long int rem = p - win * w;
  long long int rem2 = rem % d;
  t = w % d;
  for (long long int i = 0; i <= d; i++) {
    if ((i * t + rem2) % d == 0) {
      x = win - i, y = (i * w + rem) / d, z = n - x - y;
      if (z < 0) continue;
      f = 1;
      break;
    }
  }
  if (f) {
    cout << x << " " << y << " " << z << endl;
    return 0;
  } else
    cout << -1 << endl;
}
