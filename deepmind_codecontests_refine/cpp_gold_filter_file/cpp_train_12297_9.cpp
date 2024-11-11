#include <bits/stdc++.h>
using namespace std;
int q;
int l, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> q;
  while (q--) {
    cin >> l >> r;
    if (l % 2 != 0) {
      int tmp = (r - l + 1) / 2;
      if ((l - r + 1) % 2)
        cout << tmp - r << "\n";
      else
        cout << tmp << "\n";
    } else {
      int tmp = (r - l + 1) / 2;
      if ((l - r + 1) % 2 != 0)
        cout << -(tmp - r) << "\n";
      else
        cout << -tmp << "\n";
    }
  }
  return 0;
}
