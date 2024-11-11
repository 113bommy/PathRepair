#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, x1, y1, x2, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  int x1_ = x1 + y1;
  int y1_ = x1 - y1;
  int x2_ = x2 + y2;
  int y2_ = x2 - y2;
  x1 = x1_ / (2 * a);
  if (x1_ > 0) x1++;
  x2 = x2_ / (2 * a);
  if (x2_ > 0) x2++;
  y1 = y1_ / (2 * b);
  if (y1_ > 0) x1++;
  y2 = y2_ / (2 * b);
  if (y2_ > 0) y2++;
  cout << max(abs(y2 - y1), abs(x1 - x2)) << '\n';
  return 0;
}
