#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x;
  cin >> x;
  cout << x + 8 + x % 2 << " " << 8 + x % 2 << endl;
  return;
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
