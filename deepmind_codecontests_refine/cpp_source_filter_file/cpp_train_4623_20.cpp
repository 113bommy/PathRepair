#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, x[N], y[N];
int X[N], Y[N], cnt[2][2];
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%d%d", &x[i], &y[i]);
    X[i] = x[i];
    Y[i] = y[i];
  }
  sort(X + 1, X + n + 1);
  sort(Y + 1, Y + n + 1);
  int m = (n + 1) / 2, cx = X[m], cy = Y[m];
  int dx = X[m + 1] - X[m], dy = Y[m + 1] - Y[m];
  if (n & 1) {
    dx = min(dx, X[m] - X[m - 1]);
    dy = min(dy, Y[m] - Y[m - 1]);
  }
  long long ans = 0;
  bool fl = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    ans += abs(x[i] - cx) + abs(y[i] - cy);
    ++cnt[x[i] <= cx][y[i] <= cy];
    if (x[i] == cx && y[i] == cy) fl = 1;
  }
  if (cnt[0][0] && cnt[0][1])
    if ((n & 1) || fl) ans -= min(dx, dy);
  printf("%lld\n", ans * 2);
}
