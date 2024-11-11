#include <bits/stdc++.h>
using namespace std;
int n, res, d[3][107], a, b, da, db;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a, &b);
    if (a == 1)
      d[1][da++] = b;
    else
      d[2][db++] = b;
    res += a;
  }
  sort(d[1], d[1] + da);
  sort(d[2], d[2] + db);
  for (int i = 0; i <= da; ++i)
    for (int j = 0; j <= db; ++j) {
      int s = 0;
      for (int k = 0; k < da - i; ++k) s += d[1][k];
      for (int k = 0; k < db - j; ++k) s += d[2][k];
      if (i + 2 * j >= s && res > i + 2 * j) res = i + 2 * j;
    }
  cout << res << endl;
  return 0;
}
