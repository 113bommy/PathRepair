#include <bits/stdc++.h>
using namespace std;
int l, r, x, y, a, b, c, d, ans;
int find(int L, int yo) { return (L - 1) / yo * yo + yo; }
int main() {
  cin >> l >> r >> x >> y;
  for (int i = 30; i >= 0; --i) {
    a = find(l, 1 << i);
    b = find(x, 1 << i);
    if (a > r || b > y) continue;
    c = (r - a) / (1 << i) + 1;
    d = (y - b) / (1 << i) + 1;
    if (c > 3 && d > 3) {
      ans = max(ans, 2 << i);
      break;
    }
    c = min(c, 3);
    d = min(d, 3);
    for (int j = 0; j < c; ++j)
      if (((a + j * (1 << i)) / (1 << i)) & 1)
        for (int k = 0; k < d; ++k)
          if (((b + k * (1 << i)) / (1 << i)) & 1)
            ans = max(ans, min((1 << i) - 1, min(a + j * (1 << i) - l,
                                                 b + k * (1 << i) - x)) +
                               min((1 << i) - 1, min(r - a - j * (1 << i),
                                                     y - b - k * (1 << i))) +
                               1);
  }
  cout << ans << endl;
  return 0;
}
