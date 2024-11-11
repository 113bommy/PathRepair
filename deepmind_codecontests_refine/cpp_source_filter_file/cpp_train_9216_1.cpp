#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d, p, q, r, s, flag = 0;
  cin >> n >> a >> b >> c >> d;
  for (p = 1; p <= n; p++) {
    q = p + b - c;
    r = p + a - d;
    s = a + q - d;
    if (q >= 1 && r >= 1 && s >= 1 && q <= n && r <= n && s <= n) {
      flag++;
    } else {
      continue;
    }
  }
  cout << flag * n;
}
