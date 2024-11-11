#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;
long long x, second, res, xx, first;
int main() {
  cin >> second >> x;
  xx = x;
  if ((second & 1) != (x & 1)) {
    cout << 0;
    return 0;
  }
  res = 1;
  while (xx) {
    if (xx & 1) res *= 2;
    xx /= 2;
  }
  if (second == x) {
    cout << res - 2;
    return 0;
  }
  first = second - x;
  if (first < 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i <= 50; i++) {
    long long z = (1ll << (i));
    long long zz = (1ll << (i + 1));
    if ((x & z) > 0 && (first & zz) > 0) {
      cout << 0;
      return 0;
    }
  }
  cout << res;
  return 0;
}
