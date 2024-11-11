#include <bits/stdc++.h>
const int SZ = 1e5 + 5;
using namespace std;
int main() {
  int n, d, h;
  scanf("%d%d%d", &n, &d, &h);
  if (h * 2 < d || (h == d && h == 1 && n > 2)) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= h; i++) cout << i << ' ' << i + 1 << '\n';
  int p = 1, c = h + 2;
  for (int i = 1; i <= d - h; i++) cout << p << ' ' << c << '\n', p = c, c++;
  for (int i = c; i <= n; i++) cout << 2 << ' ' << i << '\n';
}
