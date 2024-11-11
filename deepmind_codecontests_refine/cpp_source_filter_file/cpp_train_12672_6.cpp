#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int a[maxn];
char s[maxn];
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  int l, r, x, y;
  while (cin >> l >> r >> x >> y) {
    if (x == y) {
      if (x > l && x < r)
        cout << 1 << endl;
      else
        cout << 0 << endl;
      continue;
    }
    if (y % x) {
      cout << "0" << endl;
      continue;
    }
    y /= x;
    int da = 0;
    for (int i = 1; i <= sqrt(y); i++) {
      if (i * x < l || i * x > r) continue;
      if (y % i) continue;
      if (y / i * x > r || y / i * x < l) continue;
      if (gcd(i, y / i) != 1) continue;
      da += 2;
    }
    cout << da << endl;
  }
}
