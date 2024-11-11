#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << endl;
    return;
  }
  int val = a - b;
  if (val < 0) {
    if (val & 1)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  } else {
    if (val & 1)
      cout << 2 << endl;
    else
      cout << 1 << endl;
  }
  return;
}
int main() {
  int TC;
  cin >> TC;
  while (TC--) {
    solve();
  }
  return 0;
}
