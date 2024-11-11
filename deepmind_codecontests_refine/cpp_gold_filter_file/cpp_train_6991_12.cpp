#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int x, y, z;
  cin >> x >> y >> z;
  if (x > y + z) {
    cout << "+" << endl;
  } else if (y > x + z) {
    cout << "-" << endl;
  } else if (z == 0 && (x == y + z || y == x + z)) {
    cout << "0" << endl;
  } else {
    cout << "?" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
