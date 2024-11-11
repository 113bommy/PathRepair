#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int a = r / 2;
    if (a >= l) {
      if (r % 2 == 0)
        cout << r - a - 1 << "\n";
      else
        cout << r - a << "\n";
    } else
      cout << r - l << "\n";
  }
  return 0;
}
