#include <bits/stdc++.h>
using namespace std;
long long a, b, p, x, y, r, l, res;
int main() {
  cin >> a >> b >> p >> x;
  r = 1;
  for (int i = 0; i < p - 2; i++) r = r * a % p;
  y = b;
  for (int i = 0; i < p - 1; i++) {
    l = i - y;
    if (l < 0) l += p;
    if (x >= i && l <= (x - i) / (p - 1)) {
      res += ((x - i) / (p - 1) - l) / p + 1;
      if (l == 0 && i == 0) res--;
    }
    y = y * r % p;
  }
  cout << res << endl;
  return 0;
}
