#include <bits/stdc++.h>
using namespace std;
const double pi = 2.0 * acos(0.0);
const double eps = 1.0e-9;
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
const int dr6[] = {1, 1, 0, -1, -1, 0}, dc6[] = {0, 1, 1, 0, -1, -1};
const int dr8[] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main(void) {
  int kase = 1000000000;
  for (int ks = 1, n, m; ks <= kase && cin >> n >> m; ++ks) {
    int l[128], r[128], t[128], c[128], s = 0;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i] >> t[i] >> c[i];
    for (int i = 1; i <= n; ++i) {
      int winner = -1;
      for (int j = 0; j < n; ++j)
        if (l[j] <= i && r[j] >= i && (winner < 0 || t[j] < t[winner]))
          winner = j;
      if (winner >= 0) s += c[winner];
    }
    cout << s << endl;
  }
  return 0;
}
