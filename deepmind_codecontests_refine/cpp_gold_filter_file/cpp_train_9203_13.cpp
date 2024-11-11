#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[5], b[5], c[5], d[5], x, y;
  cin >> n;
  for (int i = 0; i < 4; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  for (int i = 0; i < 4; ++i) {
    x = min(a[i], b[i]);
    y = min(c[i], d[i]);
    if (x + y <= n) {
      cout << i + 1 << " " << x << " " << n - x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
