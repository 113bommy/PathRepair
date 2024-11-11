#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (l < r / 2 + 1) {
      cout << (r - 1) / 2 << "\n";
    } else {
      cout << r - l << "\n";
    }
  }
}
