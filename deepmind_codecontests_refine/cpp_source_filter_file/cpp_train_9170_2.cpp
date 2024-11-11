#include <bits/stdc++.h>
using namespace std;
long long n, q, x, y;
signed main() {
  cin >> n >> q;
  for (long long i = 0; i < q; i++) {
    cin >> x >> y;
    if ((x + y) % 2 == 0) {
      if (true) {
        cout << (((n * (x - 1)) + y) + 1) / 2 << '\n';
      } else {
      }
    } else {
      if (true) {
        cout << (((n * (x - 1)) + 1 + y) / 2) + ((n * n) / 2) + 1 << '\n';
      }
    }
  }
}
