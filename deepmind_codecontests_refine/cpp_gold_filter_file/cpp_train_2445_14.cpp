#include <bits/stdc++.h>
using namespace std;
long long a, b, n, l, t, m, L, R, M, i;
int main() {
  cin >> a >> b >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> t >> m;
    if (t < a + (l - 1) * b) {
      cout << -1 << endl;
      continue;
    }
    L = 1;
    R = 10000000;
    while (L < R) {
      M = (L + R + 1) / 2;
      if ((2 * a + (l + M - 2) * b) * (M - l + 1) > t * m * 2)
        R = M - 1;
      else
        L = M;
    }
    cout << min(R, (t - a + b) / b) << endl;
  }
}
