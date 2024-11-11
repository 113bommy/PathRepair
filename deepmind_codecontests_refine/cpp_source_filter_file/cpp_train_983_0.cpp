#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, l, x, y, v[MAXN];
int c1, c2, c3, c4, ret, ret2;
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> l >> x >> y;
  c1 = c2 = c3 = c4 = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i < n; ++i) {
    if (v[lower_bound(v + i + 1, v + n + 1, v[i] + x) - v] == v[i] + x) c1 = 1;
    if (v[lower_bound(v + i + 1, v + n + 1, v[i] + y) - v] == v[i] + y) c2 = 1;
    if (v[lower_bound(v + i + 1, v + n + 1, v[i] + x + y) - v] ==
        v[i] + x + y) {
      c3 = 1;
      ret = v[i] + x;
    }
    if (v[lower_bound(v + i + 1, v + n + 1, v[i] + abs(x - y)) - v] ==
        v[i] + abs(x - y)) {
      if (v[i] + max(x, y) <= l) {
        c4 = 1;
        ret2 = v[i] + max(x, y);
      } else if (v[i] - max(x, y) >= 0) {
        c4 = 1;
        ret2 = v[i] - max(x, y);
      }
    }
  }
  if (c1 && c2)
    cout << 0;
  else if (c3)
    cout << 1 << "\n" << ret;
  else if (c4)
    cout << 1 << "\n" << ret2;
  else {
    cout << 2 - c1 - c2 << "\n";
    if (!c1) cout << x << " ";
    if (!c2) cout << y << " ";
  }
  return 0;
}
