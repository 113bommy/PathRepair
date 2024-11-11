#include <bits/stdc++.h>
using namespace std;
int64_t n, i, k, x, v, l, r, z;
int main() {
  cin >> n;
  for (l = 0, r = n + 1; l < r - 1;) {
    k = l + r >> 1;
    for (v = 0, x = n; x > 0; z = min(k, x), v += z, x = x - z - (x - z) / 10)
      ;
    (v >= (n + 1) / 2 ? r : l) = k;
  }
  cout << r;
}
