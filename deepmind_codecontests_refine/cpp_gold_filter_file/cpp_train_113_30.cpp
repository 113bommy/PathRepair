#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
void solve() {
  long long n, m;
  long long a = 0;
  long long b = 0;
  cout << "? " << a << " " << b << '\n';
  long long y;
  cin >> y;
  for (long long i = 29; i >= 0; i--) {
    cout << "? " << a << " " << b + (1LL << i) << '\n';
    cout.flush();
    long long x = 0;
    cin >> x;
    cout << "? " << a + (1LL << i) << " " << b << '\n';
    cout.flush();
    long long z = 0;
    cin >> z;
    if (x == 1 and z == -1) {
      a = a + (1LL << i);
      b = b + (1LL << i);
    } else if (x == -1 and z == 1) {
      continue;
    } else if (x == 1 and z == 1) {
      if (y == 1)
        a = a + (1 << i);
      else
        b = b + (1 << i);
      y = 1;
    } else if (x == -1 and z == -1) {
      if (y == 1)
        a = a + (1 << i);
      else
        b = b + (1 << i);
      y = -1;
    } else {
      if (y == 1)
        a = a + (1 << i);
      else
        b = b + (1 << i);
      y = 0;
    }
  }
  cout << "! " << a << " " << b << '\n';
  cout.flush();
}
signed main() {
  long long t;
  ios_base::sync_with_stdio(false);
  t = 1;
  while (t--) solve();
  return 0;
}
