#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x;
  cin >> x;
  if (x == 2)
    cout << "1 1\n";
  else if (x % 2 == 0) {
    x -= 2;
    x *= 2;
    cout << "2 " << x / 2 << "\n";
  } else
    cout << "1 " << x - 1 << "\n";
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
