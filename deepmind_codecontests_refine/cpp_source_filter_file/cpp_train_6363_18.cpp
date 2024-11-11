#include <bits/stdc++.h>
using namespace std;
const int N = 200010, Mod = 998244353;
const double pi = acos(-1.0);
int x[3], y[3], yy[3];
int main() {
  for (int i = 0; i < 3; i++) cin >> x[i] >> y[i], yy[x[i]] = y[i];
  sort(x, x + 3), sort(y, y + 3);
  printf("%d\n", x[2] - x[0] + y[2] - y[0] + 1);
  for (int i = x[0]; i < x[1]; i++) printf("%d %d\n", i, yy[x[0]]);
  for (int i = x[1] + 1; i <= x[2]; i++) printf("%d %d\n", i, yy[x[2]]);
  for (int i = y[0]; i <= y[2]; i++) printf("%d %d\n", x[1], i);
  return 0;
}
