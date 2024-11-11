#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, l, r;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    cin >> l >> r;
    if (l == r) {
      if (l % 2 == 0)
        cout << l << endl;
      else if (l % 2 != 0)
        cout << -l << endl;
    } else if (l % 2 != 0 && r % 2 == 0)
      cout << (((r * (r + 1)) - l * (l - 1)) - (r * r - (l - 1) * (l - 1))) / 2
           << endl;
    else if (l % 2 == 0 && r % 2 != 0)
      cout << (((r * (r + 1)) - l * (l - 1)) - ((r + 1) * (r + 1) - l * l)) / 2
           << endl;
    else if (l % 2 != 0 && r % 2 != 0)
      cout << (((r * (r + 1)) - l * (l - 1)) -
               ((r + 1) * (r + 1) - (l - 1) * (l - 1))) /
                  2
           << endl;
    else if (l % 2 == 0 && r & 2 == 0)
      cout << (((r * (r + 1)) - l * (l - 1)) - (r * r - l * l)) / 2 << endl;
  }
  return 0;
}
