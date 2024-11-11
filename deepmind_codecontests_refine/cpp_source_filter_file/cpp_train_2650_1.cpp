#include <bits/stdc++.h>
using namespace std;
long long l, r, k;
void f2() {}
int main() {
  cin >> l >> r >> k;
  if (k >= 4) {
    long long x = (l - 1) / 4 * 4 + 4;
    if (x >= l && x + 3 <= r) {
      cout << (x ^ (x + 1) ^ (x + 2) ^ (x + 3)) << endl;
      cout << 4 << endl;
      cout << x << " " << x + 1 << " " << x + 2 << " " << x + 3 << endl;
      return 0;
    }
  }
  if (k >= 3) {
    for (int i = 0; i < 100; i++) {
      long long x0 = 3ll << i;
      long long x1 = (3ll << i) - 1;
      long long x2 = (2ll << i) - 1;
      if (x0 > r) {
        break;
      }
      if (x2 < l) {
        continue;
      }
      cout << 0 << endl;
      cout << 3 << endl;
      cout << x2 << " " << x1 << " " << x0 << endl;
      return 0;
    }
  }
  if (l == 1) {
    cout << l << endl;
    cout << 1 << endl;
    cout << l << endl;
    return 0;
  }
  if (k >= 2) {
    long long x = (l - 1) / 2 * 2 + 2;
    if (x + 1 <= r) {
      cout << 1 << endl;
      cout << 2 << endl;
      cout << x << " " << (x + 1) << endl;
      return 0;
    }
  }
  if (k == 1 || l == r || (l ^ r) > l) {
    cout << l << endl;
    cout << 1 << endl;
    cout << l << endl;
    return 0;
  }
  cout << (l ^ r) << endl;
  cout << 2 << endl;
  cout << l << " " << r << endl;
  return 0;
}
