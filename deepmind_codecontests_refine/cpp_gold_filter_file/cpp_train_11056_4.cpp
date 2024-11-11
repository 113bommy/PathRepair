#include <bits/stdc++.h>
using namespace std;
long long n, x, a, b;
void solve() {
  cin >> a >> b;
  if (a == 1) {
    if (b == 1) {
      cout << "YES" << endl;
      return;
    } else {
      cout << "NO" << endl;
      return;
    }
  } else if (a == 2 or a == 3) {
    if (b > 3) {
      cout << "NO" << endl;
      return;
    } else {
      cout << "YES" << endl;
      return;
    }
  } else {
    cout << "YES" << endl;
  }
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
