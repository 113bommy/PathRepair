#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q, i, j, ans, l, r, d;
  cin >> q;
  while (q--) {
    cin >> l >> r >> d;
    if (d < l || d > r)
      cout << d << endl;
    else {
      ans = 1 + r / d;
      cout << ans * d << endl;
    }
  }
  return 0;
}
