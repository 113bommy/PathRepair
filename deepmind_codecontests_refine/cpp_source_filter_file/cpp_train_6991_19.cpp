#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
void solve() {
  int x, y, z;
  cin >> x >> y >> z;
  if (x - y > z) {
    cout << "+";
  } else if (y - x > z) {
    cout << "-";
  } else if (x - y == z) {
    cout << "0";
  } else {
    cout << "?";
  }
}
