#include <bits/stdc++.h>
using namespace std;
int n, m, i, k, q, type, l, r, zn;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> m >> q;
  l = 1;
  r = n;
  while (q--) {
    cin >> type >> zn;
    zn += l - 1;
    if (type == 0) {
      if (zn >= k)
        r = zn;
      else
        l = zn + 1;
    } else {
      if (zn <= k)
        l--;
      else
        r++;
    }
    cout << r - l + 1 << " " << k - l + 1 << '\n';
  }
  return 0;
}
