#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long f[744][744], g[744 * 744];
class {
 public:
  int q;
  void solve() {
    cin >> q;
    while (q--) {
      int t, x, y;
      cin >> t >> x >> y;
      if (t == 1) {
        for (int i = 1; i < 744; ++i) {
          f[i][x % i] += y;
        }
        g[x] += y;
      } else {
        if (x < 744) {
          cout << f[x][y] << "\n";
        } else {
          long long res = 0;
          for (int i = y; i <= 50000; i += x) {
            res += g[i];
          }
          cout << res << "\n";
        }
      }
    }
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
