#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(1);
  cout << fixed;
  double n, x, y;
  cin >> n >> x >> y;
  double s = (y * n) / 100;
  int p = ceil(s) - x;
  if (p >= 0)
    cout << p;
  else
    cout << 0;
}
