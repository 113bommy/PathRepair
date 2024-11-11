#include <bits/stdc++.h>
using namespace std;
int n, k[55];
void solve() {
  long long x, y, z;
  cin >> x >> y >> z;
  if (x % z == 0 || y % z == 0) {
    cout << x / z + y / z << " " << 0 << "\n";
  } else {
    long long x1 = x - (x / z * z);
    long long x2 = y - (y / z * z);
    cout << (x + y) / z << " ";
    if (x1 + x2 >= z)
      cout << z - max(x1, x2) << "\n";
    else
      cout << 0 << "\n";
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
