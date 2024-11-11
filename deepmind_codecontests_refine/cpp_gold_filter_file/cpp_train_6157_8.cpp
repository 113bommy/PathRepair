#include <bits/stdc++.h>
using namespace std;
long long n, sx, sy, ex, ey, dx, dy, wdx[100005], wdy[100005], l, r, mid;
char c;
int possible(long long x) {
  long long dxp, dyp;
  dxp = dx + wdx[x % n] + wdx[n] * (x / n);
  dyp = dy + wdy[x % n] + wdy[n] * (x / n);
  if (abs(dxp) + abs(dyp) <= x)
    return 1;
  else
    return 0;
}
int main() {
  cin >> sx >> sy >> ex >> ey >> n;
  dx = ex - sx;
  dy = ey - sy;
  getchar();
  for (int i = 1; i <= n; i++) {
    c = getchar();
    wdx[i] = wdx[i - 1];
    wdy[i] = wdy[i - 1];
    if (c == 'R') wdx[i]--;
    if (c == 'L') wdx[i]++;
    if (c == 'U') wdy[i]--;
    if (c == 'D') wdy[i]++;
  }
  l = 1;
  r = 100000000000000000;
  while (l < r) {
    mid = (l + r) >> 1;
    if (possible(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (mid >= 90000000000000000)
    cout << -1 << endl;
  else
    cout << l << endl;
}
