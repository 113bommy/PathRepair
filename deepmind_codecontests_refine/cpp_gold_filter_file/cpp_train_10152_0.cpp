#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  unsigned long long l, r, k, t;
  cin >> l >> r >> k;
  bool f = true;
  t = 1;
  while (t <= r) {
    if (t >= l) f = false, (cout << t << ' ');
    if (t * k / k != t) break;
    t *= k;
  }
  if (f) cout << -1;
  return 0;
}
