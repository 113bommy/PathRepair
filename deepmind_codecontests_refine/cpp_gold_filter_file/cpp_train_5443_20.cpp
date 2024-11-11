#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double l, r;
    cin >> l >> r;
    if ((r + 1) / 2 <= l)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
