#include <bits/stdc++.h>
using namespace std;
const int N = 150;
long long s, ans;
inline long long dp(int ot, int la, int lb, long long sm) {
  static long long f[N][2], las[N][2];
  for (int a = 0, nn = int(ot + 1); a < nn; ++a)
    for (int re = 0, nn = int(2); re < nn; ++re) f[a][re] = 0;
  f[0][0] = 1;
  for (int i = 0; (1LL << i) <= sm; ++i) {
    for (int a = 0, nn = int(ot + 1); a < nn; ++a)
      for (int re = 0, nn = int(2); re < nn; ++re) {
        las[a][re] = f[a][re];
        f[a][re] = 0;
      }
    for (int ca = 0, nn = int(2); ca < nn; ++ca)
      if (i < la || ca == 0)
        for (int cb = 0, nn = int(2); cb < nn; ++cb)
          if (i < lb || cb == 0) {
            for (int re = 0, nn = int(2); re < nn; ++re) {
              int dg = ca + cb + re;
              if ((dg & 1) != ((sm << i) & 1)) continue;
              for (int al = 0; al + ca + cb <= ot; ++al)
                f[al + ca + cb][dg / 2] += las[al][re];
            }
          }
  }
  return f[ot][0];
}
int main() {
  cin >> s, ans = 0;
  for (int a = 0, nn = int(59); a < nn; ++a)
    for (int b = 0, nn = int(59); b < nn; ++b) {
      long long mul = (1LL << a + 1) + (1LL << b + 1) - 3;
      long long lca = s / mul;
      if (!lca) continue;
      long long res = s - lca * mul - ((1LL << b) - 1);
      for (int ones = 0, nn = int(a + b + 1); ones < nn; ++ones) {
        long long aandb = res + ones;
        if (aandb < 0 || aandb % 2) continue;
        aandb /= 2;
        ans += dp(ones, max(a - 1, 0), max(b - 1, 0), aandb);
      }
    }
  cout << ans << endl;
  return 0;
}
