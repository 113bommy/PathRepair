#include <bits/stdc++.h>
using namespace std;
int t, a, b;
void nhap() { cin >> t; }
void solve() {
  for (int i = 1; i <= t; ++i) {
    cin >> a >> b;
    if (a == b)
      cout << 0 << endl;
    else if (a > b) {
      if (a % 2 == b % 2) cout << 1 << endl;
      if (a % 2 != b % 2) cout << 2 << endl;
    } else {
      if (a % 2 == 1 & b % 2 == 1) cout << 2 << endl;
      if (a % 2 == 1 & b % 2 == 0) cout << 1 << endl;
      if (a % 2 == 0 & b % 2 == 0) cout << min(b - a, 2) << endl;
      if (a % 2 == 0 & b % 2 == 1) cout << 1 << endl;
    }
  }
}
int main() {
  nhap();
  solve();
  return 0;
}
