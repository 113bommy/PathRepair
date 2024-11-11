#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int k;
  cin >> k;
  if (k >= s.size()) {
    int td = (k + s.size()) / 2;
    cout << td * 2 << endl;
  } else {
    int maxtd = (k + s.size()) / 2;
    int sl = s.size();
    bool ok = false;
    int res = 0;
    for (int tdsz = maxtd; tdsz >= 1 && !ok; --tdsz) {
      for (int piv = 0; piv <= s.size() + k - 2 * tdsz && !ok; ++piv) {
        for (int j = piv; j < piv + tdsz && !ok; ++j) {
          if (j >= s.size() || j + tdsz >= s.size()) {
            res = tdsz * 2;
            ok = true;
            break;
          } else {
            if (s[j] != s[j + tdsz]) {
              break;
            }
            if (j + tdsz == piv + 2 * tdsz - 1) {
              res = tdsz * 2;
              ok = true;
            }
          }
        }
      }
    }
    assert(res >= 2);
    cout << res << endl;
  }
  return 0;
}
