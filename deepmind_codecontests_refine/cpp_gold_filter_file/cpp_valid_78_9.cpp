#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, ans, n;
  cin >> n;
  while (n--) {
    cin >> l >> r;
    int c = (r / 2) + 1;
    if (l < c) {
      ans = r % c;
      cout << ans << endl;
    } else {
      ans = r % l;
      cout << ans << endl;
    }
  }
  return 0;
}
