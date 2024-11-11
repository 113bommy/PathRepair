#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long l, r, k;
  cin >> l >> r >> k;
  unsigned long long t = 1, er;
  bool tg = 0;
  while (true) {
    if (t >= l && t <= r) {
      cout << t << " ";
      tg = 1;
      er = t * k;
      if (er / t != k) {
        break;
      }
      t = er;
    } else if (t <= l) {
      er = t * k;
      if (er / t != k) {
        break;
      }
      t = er;
    } else {
      break;
    }
  }
  if (!tg) cout << -1;
}
