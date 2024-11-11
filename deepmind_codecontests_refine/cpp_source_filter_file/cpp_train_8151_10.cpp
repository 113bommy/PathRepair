#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int f1, f2, f3;
  f1 = (k * l) / n;
  f2 = c * d;
  f3 = p / np;
  int ans = min(f1, f2);
  ans = min(ans, f3) / n;
  cout << ans;
  return 0;
}
