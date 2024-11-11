#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l + 1 <= r)
      cout << l << " " << l + 1 << endl;
    else
      cout << "-1 -1" << endl;
  }
  return 0;
}
