#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d;
  cin >> n >> d;
  int q;
  cin >> q;
  for (int x, y; q--;) {
    cin >> x >> y;
    int l, r, lvl = 0;
    l = r = d;
    int pl = -1;
    int pr = +1;
    bool yes = false;
    do {
      for (int a = l; a <= r; a++)
        if (lvl == y && a == x) yes = true;
      l += pl;
      r += pr;
      if (l == 0) pl = +1;
      if (r == n) pr = -1;
      lvl++;
    } while (l != r && !yes);
    cout << (yes ? "YES" : "NO") << '\n';
  }
  return false;
}
