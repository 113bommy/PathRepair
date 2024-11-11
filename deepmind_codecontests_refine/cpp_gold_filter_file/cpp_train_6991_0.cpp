#include <bits/stdc++.h>
using namespace std;
long long mx = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x, y, z;
  cin >> x >> y >> z;
  if (x + z < y) {
    cout << "-" << '\n';
    return 0;
  }
  if (y + z < x) {
    cout << "+" << '\n';
    return 0;
  }
  if (x == y && z == 0) {
    cout << 0 << '\n';
    return 0;
  }
  int bb = abs(x - y);
  if (bb <= z) {
    cout << "?" << '\n';
    return 0;
  }
  return 0;
}
