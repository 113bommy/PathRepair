#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, d, p = 1, t;
  set<int> s;
  cin >> n;
  for (k = 1; k <= n; k++) {
    cin >> t;
    s.insert(t);
  }
  while (p == 1) {
    d = *s.rbegin();
  _4:
    d = d / 2;
    if (s.count(d) == 0 && d > 0) {
      s.erase(*s.rbegin());
      s.insert(d);
    } else if (d > 1)
      goto _4;
    else {
      for (k = 1; k <= n; k++) {
        cout << *s.rbegin() << " ";
        s.erase(*s.rbegin());
      }
      return 0;
    }
  }
  return 0;
}
