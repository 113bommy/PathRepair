#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (2 * l > r && l >= r / 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
