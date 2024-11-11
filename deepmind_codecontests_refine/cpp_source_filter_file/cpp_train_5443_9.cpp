#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r < 2 * l - 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
