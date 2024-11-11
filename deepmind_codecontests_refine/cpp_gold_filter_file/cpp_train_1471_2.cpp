#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int x[N], y[N];
int main() {
  int n;
  scanf("%d", &n);
  int maxx, maxy, minx, miny;
  int ans;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    if (i == 1)
      maxx = minx = x[i], maxy = miny = y[i];
    else
      maxx = max(maxx, x[i]), minx = min(minx, x[i]), maxy = max(maxy, y[i]),
      miny = min(miny, y[i]);
  }
  if (n == 3)
    printf("%d\n", 2 * (maxx - minx) + 2 * (maxy - miny));
  else {
    ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, 2 * (maxx - x[i] + maxy - y[i]));
      ans = max(ans, 2 * (x[i] - minx + maxy - y[i]));
      ans = max(ans, 2 * (maxx - x[i] + y[i] - miny));
      ans = max(ans, 2 * (x[i] - minx + y[i] - miny));
    }
    printf("%d ", ans);
    for (int i = 4; i <= n; i++)
      printf("%d%c", 2 * (maxx - minx + maxy - miny), i == n ? '\n' : ' ');
  }
  return 0;
}
