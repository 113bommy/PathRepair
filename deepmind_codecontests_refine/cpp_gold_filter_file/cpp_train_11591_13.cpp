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
  for (int ks = 1, n, k; ks <= kase && cin >> n >> k; ++ks) {
    int e[4096] = {0}, s = 0;
    for (int i = 0, t, d; i < n && cin >> t >> d; ++i) {
      for (int j = k; j >= 0; --j) {
        e[j + 1] = min(e[j + 1], e[j]);
        s = max(s, t - 1 - e[j]);
        e[j] = max(e[j], t - 1) + d;
      }
    }
    for (int i = 0; i <= k; ++i) s = max(s, 86400 - e[i]);
    cout << s << endl;
  }
  return 0;
}
