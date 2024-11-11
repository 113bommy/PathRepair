#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x;
  cin >> x;
  cout << 8 + x % 2 << " " << x + 8 + x % 2 << endl;
  return;
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
