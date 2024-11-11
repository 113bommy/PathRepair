#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (r >= 2 * l)
      cout << l << " " << 2 * l << "\n";
    else
      cout << "-1 -1\n";
  }
}
