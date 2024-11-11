#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int r, l;
  cin >> r >> l;
  if ((l + 1) / 2 < r) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
