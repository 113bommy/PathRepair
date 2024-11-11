#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, x[N], y[N], xs[N], ys[N], cnt[2][2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    xs[i] = x[i], ys[i] = y[i];
  }
  sort(xs + 1, xs + n + 1);
  sort(ys + 1, ys + n + 1);
  int m = (n + 1) / 2;
  int cx = xs[m], cy = ys[m];
  int dx = xs[m + 1] - xs[m], dy = ys[m + 1] - ys[m];
  if (n & 1) {
    dx = min(dx, xs[m] - xs[m - 1]);
    dy = min(dy, ys[m] - ys[m - 1]);
  }
  long long ans = 0;
  bool flag = 0;
  for (int i = 1; i <= n; i++) {
    ans += abs(x[i] - cx) + abs(y[i] - cy);
    ++cnt[x[i] <= cx][y[i] <= cy];
    if (x[i] == cx && y[i] == cy) flag = 1;
  }
  if (cnt[0][0] && cnt[0][1]) {
    if (n % 2 == 0 || flag) ans -= min(dx, dy);
  }
  printf("%I64d\n", ans * 2);
}
