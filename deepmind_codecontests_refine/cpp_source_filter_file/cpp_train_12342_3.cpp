#include <bits/stdc++.h>
using namespace std;
void fail() {
  cout << "Impossible\n";
  exit(0);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t a[2][2];
  cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
  int64_t z = -1, o = -1;
  const int64_t maxn = 1e6;
  for (int64_t i = 0; i <= maxn; i++) {
    if (i * (i - 1) / 2 == a[0][0]) z = i;
    if (i * (i - 1) / 2 == a[1][1]) o = i;
  }
  if (z == -1 || o == -1) fail();
  int64_t O = o, Z = z;
  int64_t AA[2][2];
  AA[0][0] = a[0][0];
  AA[0][1] = a[0][1];
  AA[1][0] = a[1][0];
  AA[1][1] = a[1][1];
  for (int64_t A = 0; A <= (a[0][0] == 0); A++)
    for (int64_t B = 0; B <= (a[1][1] == 0); B++) {
      int64_t a[2][2] = {{AA[0][0], AA[0][1]}, {AA[1][0], AA[1][1]}};
      int64_t z = Z - A;
      int64_t o = O - B;
      int64_t n = o + z;
      if (n > maxn || n == 0) continue;
      string s;
      for (int64_t i = 0; i < n; i++) {
        if (o <= a[1][0] && z > 0) {
          a[1][0] -= o;
          z--;
          s += "0";
        } else {
          a[0][1] -= z;
          o--;
          s += "1";
        }
      }
      if (a[0][1] == 0 && a[1][0] == 0 && o == 0 && z == 0) {
        cout << s << "\n";
        return 0;
      }
    }
  fail();
  return 0;
}
