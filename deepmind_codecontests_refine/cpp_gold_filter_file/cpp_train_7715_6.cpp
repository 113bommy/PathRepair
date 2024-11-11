#include <bits/stdc++.h>
using namespace std;
int n, a[200010], sx[200010], sy[200010], ex, ey;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char in[200010];
bool f(int x) {
  for (int i = 1; i <= n - x + 1; i++) {
    int cx = sx[n] - (sx[i + x - 1] - sx[i - 1]);
    int cy = sy[n] - (sy[i + x - 1] - sy[i - 1]);
    int val = abs(cx - ex) + abs(cy - ey);
    if (val <= x && val % 2 == x % 2) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%s%d%d", &n, in + 1, &ex, &ey);
  for (int i = 1; i <= n; i++) {
    if (in[i] == 'U') a[i] = 0;
    if (in[i] == 'D') a[i] = 2;
    if (in[i] == 'L') a[i] = 3;
    if (in[i] == 'R') a[i] = 1;
    sx[i] = sx[i - 1] + dir[a[i]][0];
    sy[i] = sy[i - 1] + dir[a[i]][1];
  }
  int lo = 0, hi = n + 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (f(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%d", lo == n + 1 ? -1 : lo);
  return 0;
}
