#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main() {
  int T;
  long long x, y, p, q;
  cin >> T;
  while (T--) {
    cin >> x >> y >> p >> q;
    if (p == 0) {
      if (x)
        cout << -1 << '\n';
      else
        cout << 0 << '\n';
      continue;
    }
    if (p == q) {
      if (x != y)
        cout << -1 << '\n';
      else
        cout << 0 << '\n';
      continue;
    }
    long long F = (y - x + q - p - 1) / (q - p) * q;
    long long S = (x + p - 1) / p * q;
    cout << max(F, S) - y << '\n';
  }
  return 0;
}
