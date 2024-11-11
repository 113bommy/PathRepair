#include <bits/stdc++.h>
using namespace std;
int k, a, b, v, nr, c;
int main() {
  cin >> k >> a >> b >> v;
  while (a > 0) {
    nr++;
    if (b >= k - 1) {
      c = v * k;
      b = b - k + 1;
    } else {
      c = (b + 1) * v;
      b = 0;
    }
    a -= c;
  }
  cout << nr;
  return 0;
}
