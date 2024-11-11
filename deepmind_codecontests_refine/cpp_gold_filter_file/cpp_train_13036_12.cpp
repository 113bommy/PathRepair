#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 1e9 + 5;
const int N = 1e6 + 5;
int d[10];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int i, t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int ans = -inf, f1, f2, f3;
    for (i = 1; i < 7; ++i) d[i] = i;
    do {
      int x = a, y = b, z = c, res = 0;
      for (i = 1; i < 7; ++i) {
        int r1 = 0, r2 = 0, r3 = 0;
        if (d[i] & 1) ++r3;
        if (d[i] & 2) ++r2;
        if (d[i] & 4) ++r1;
        if (x >= r1 && y >= r2 && z >= r3) {
          ++res;
          x -= r1;
          y -= r2;
          z -= r3;
        }
      }
      if (x >= 1 && y >= 1 && z >= 1) ++res;
      ans = max(ans, res);
    } while (next_permutation(d + 1, d + 7));
    cout << ans << '\n';
  }
  return 0;
}
