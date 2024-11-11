#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t q;
  cin >> q;
  while (q--) {
    int64_t x, y;
    cin >> x >> y;
    if (x > 3)
      cout << "YES\n";
    else if (!(x ^ 1))
      cout << ((y ^ 1) ? "NO\n" : "YES\n");
    else
      cout << ((y <= 3) ? "YES\n" : "NO\n");
  }
  cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
