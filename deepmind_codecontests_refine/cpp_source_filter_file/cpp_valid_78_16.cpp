#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (l + 1 == r)
      cout << r % l << endl;
    else
      cout << (r - 1) / 2 << endl;
  }
  return 0;
}
