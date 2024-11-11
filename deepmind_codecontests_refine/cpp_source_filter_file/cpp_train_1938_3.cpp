#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, d;
  cin >> r >> d;
  int n;
  cin >> n;
  d = r - d;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y, rx;
    cin >> x >> y >> rx;
    long double distance = sqrt(x * x + y * y);
    long double temp = (rx / 2.0);
    if (distance - d - temp > 0) {
      if (r - distance - temp > 0) ans++;
    }
  }
  cout << ans;
  return 0;
}
