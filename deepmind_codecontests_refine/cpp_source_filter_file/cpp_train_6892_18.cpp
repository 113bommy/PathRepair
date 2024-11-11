#include <bits/stdc++.h>
using namespace std;
long long t1, t2, x1, x2, tt, l, r, c, a1, a2, ans = 2e18, sa;
int main() {
  cin >> t1 >> t2 >> x1 >> x2 >> tt;
  for (int i = 0; i <= x1; i++) {
    l = 0;
    r = x2;
    while (l < r) {
      c = (l + r) / 2;
      if (i == 0 || t1 == t2 || (i * t1 + c * t2) < tt * (i + c))
        l = c + 1;
      else
        r = c;
    }
    if ((i * t1 + l * t2) < tt * (i + l)) continue;
    if ((i * t1 + l * t2) * sa < ans * (i + l) ||
        (i * t1 + l * t2) * sa == ans * (i + l) && i + l > sa)
      a1 = i, a2 = l, ans = (i * t1 + l * t2), sa = i + l;
  }
  cout << a1 << " " << a2 << endl;
  return 0;
}
