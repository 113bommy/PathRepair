#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, p, q;
  cin >> l >> p >> q;
  double t, ans;
  t = l / (p + q);
  ans = t * p;
  cout << ans;
  return 0;
}
