#include <bits/stdc++.h>
using namespace std;
namespace {
long long x, y, c[7];
unsigned long long u, d, l, r, ru, ld;
void Solve() {
  cin >> x >> y;
  for (int i = 1; i <= 6; i++) cin >> c[i];
  r = min(c[6], c[1] + c[5]);
  l = min(c[3], c[2] + c[4]);
  u = min(c[2], c[1] + c[3]);
  d = min(c[5], c[4] + c[6]);
  ru = min(c[1], c[6] + c[2]);
  ld = min(c[4], c[6] + c[3]);
  if (x <= 0 && y <= 0) {
    x = -x, y = -y;
    if (x > y)
      cout << y * ld + (x - y) * l << endl;
    else
      cout << x * ld + (y - x) * d << endl;
  } else if (x >= 0 && y >= 0) {
    if (x > y)
      cout << y * ru + (x - y) * r << endl;
    else
      cout << x * ru + (y - x) * u << endl;
  } else if (x <= 0 && y >= 0)
    cout << -x * l + y * u << endl;
  else if (x >= 0 && y <= 0)
    cout << x * r + -y * d << endl;
}
}  // namespace
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int t(1);
  cin >> t;
  while (t--) Solve();
  return 0;
}
