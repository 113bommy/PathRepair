#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long q, a, z;
  cin >> q;
  while (q--) {
    cin >> a;
    z = a % 4;
    if (z == 0) {
      cout << a / 4;
    } else if (z == 1 && a >= 9) {
      cout << a / 4 - 1 << "\n";
    } else if (z == 2 && a >= 6) {
      cout << a / 4 << "\n";
    } else if (z == 3 && a >= 15) {
      cout << a / 4 - 1 << "\n";
    } else
      cout << "-1\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
