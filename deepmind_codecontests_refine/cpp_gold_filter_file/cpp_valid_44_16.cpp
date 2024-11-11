#include <bits/stdc++.h>
using namespace std;
void solve() {
  int c, d;
  cin >> c >> d;
  int a = 0, b = 0;
  if (abs(c - d) % 2 == 1) {
    cout << "-1" << '\n';
    return;
  }
  if (c == 0 && d == 0) {
    cout << "0\n";
    return;
  }
  if (c == d) {
    cout << 1 << endl;
    return;
  }
  cout << 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
