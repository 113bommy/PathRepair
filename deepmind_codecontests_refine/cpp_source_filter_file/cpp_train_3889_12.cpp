#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long a = 0, b = 0, c, d = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      a += c;
      b += c * (4 * i + 2);
      d += c * (4 * j + 2);
      ans += c * (4 * i + 2) * (4 * i + 2) + c * (4 * j + 2) * (4 * j + 2);
    }
  }
  long long xmini, ymini, xx = 0, yy = 0;
  for (int i = 0; i < n + 1; i++) {
    if (xx > 16 * a * i * i - 8 * i * b) {
      xx = 16 * a * i * i - 8 * i * b;
      xmini = i;
    }
  }
  for (int i = 0; i < m + 1; i++) {
    if (yy > 16 * a * i * i - 8 * i * d) {
      yy = 16 * a * i * i - 8 * i * d;
      ymini = i;
    }
  }
  ans += xx + yy;
  cout << ans << endl;
  cout << xmini << " " << ymini << endl;
  return 0;
}
