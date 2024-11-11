#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, h = 0, l, r;
  cin >> n >> m >> k;
  m -= n;
  l = 1;
  r = 1e5;
  while (l + 1 < r) {
    h = (l + r) / 2;
    long long xl, xr;
    xl = (h - 1 + h - min(h - 1, k - 1)) * min(h - 1, k - 1) / 2;
    xr = (h + h - min(n - k + 1, h) + 1) * min(n - k + 1, h) / 2;
    if (xl + xr > m)
      r = h;
    else
      l = h;
  }
  cout << l + 1 << endl;
  return 0;
}
