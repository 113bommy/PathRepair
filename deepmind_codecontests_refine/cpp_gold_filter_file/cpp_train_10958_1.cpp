#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c, a1, b1, c1;
  cin >> a >> b >> c >> a1 >> b1 >> c1;
  long long ans = 0, q = min(c, b1);
  ans += (2 * q);
  c -= q;
  b1 -= q;
  q = min(c, c1);
  c -= q;
  c1 -= q;
  q = min(a, c1);
  a -= q;
  c1 -= q;
  q = max(b - a1 - b1, 0LL);
  cout << ans - 2 * min(q, c1) << "\n";
}
int main() {
  long long n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
