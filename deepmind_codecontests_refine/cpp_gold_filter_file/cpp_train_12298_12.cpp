#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p1, p2, p3, t1, t2;
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  int res = 0;
  int l, r, tmp, t;
  tmp = -1;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    if (tmp != -1) {
      t = l - tmp;
      if (t >= t2 + t1) {
        res += t1 * p1 + t2 * p2 + (t - t1 - t2) * p3;
      } else {
        if (t >= t1) {
          res += t1 * p1 + (t - t1) * p2;
        } else {
          res += t * p1;
        }
      }
    }
    tmp = r;
    res += (r - l) * p1;
  }
  cout << res;
  return 0;
}
