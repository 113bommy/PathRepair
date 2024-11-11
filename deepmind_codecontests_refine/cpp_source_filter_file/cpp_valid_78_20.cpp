#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r < l * 2)
      cout << r - 1 << endl;
    else
      cout << (r - 1) / 2 << endl;
  }
  return 0;
}
