#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n, m, l = 0, r = 1E18 + 1;
  cin >> n >> m;
  if (m >= n) {
    cout << n << endl;
    return;
  }
  double th = sqrt(2 * (n - m));
  while (r - l > 1) {
    uint64_t mi = l + (r - l) / 2, p;
    if (((double)mi) > th) {
      r = mi;
    } else {
      if (mi % 2 == 0) {
        p = (mi / 2) * (mi + 1);
      } else {
        p = ((mi + 1) / 2) * mi;
      }
      if (p < (n - m)) {
        l = mi;
      } else {
        r = mi;
      }
    }
  }
  cout << (l + m + 1) << endl;
}
int main() {
  solve();
  return 0;
}
