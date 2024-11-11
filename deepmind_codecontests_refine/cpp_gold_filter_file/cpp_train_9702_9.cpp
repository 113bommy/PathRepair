#include <bits/stdc++.h>
using namespace std;
long long get(long long x, long long y) { return x / y - (x < 0); }
int main() {
  long long a, b, l, d, r, u;
  while (cin >> a >> b >> l >> d >> r >> u) {
    long long x = get(l + d, 2 * a) - get(r + u, 2 * a);
    long long y = get(l - d, 2 * b) - get(r - u, 2 * b);
    cout << abs(x) + abs(y) - min(abs(x), abs(y)) << endl;
  }
  return 0;
}
