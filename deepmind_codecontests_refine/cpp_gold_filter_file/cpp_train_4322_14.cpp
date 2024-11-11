#include <bits/stdc++.h>
using namespace std;
int ll[2005], lr[2005];
double f[2005][2005][2][2];
int a[2005];
int n, h;
double k;
double dfs(int l, int r, int al, int ar) {
  if (l > r) return 0;
  if (f[l][r][al][ar] != 0) return f[l][r][al][ar];
  double s = 0;
  s += k * 0.5 * (min(a[l] - a[l - 1] - al * h, h) + dfs(l + 1, r, 0, ar));
  s +=
      (1 - k) * 0.5 * (min(a[r + 1] - a[r] - ar * h, h) + dfs(l, r - 1, al, 0));
  if (ll[r] <= l) {
    s += k * 0.5 * (min(a[l] - a[l - 1] - h * al, h) + a[r] - a[l]);
  } else
    s += k * 0.5 * (dfs(l, ll[r] - 1, al, 1) + a[r] - a[ll[r]] + h);
  if (lr[l] >= r) {
    s += (1 - k) * 0.5 * (min(a[r + 1] - a[r] - h * ar, h) + a[r] - a[l]);
  } else
    s += (1 - k) * 0.5 * (dfs(lr[l] + 1, r, 1, ar) + a[lr[l]] - a[l] + h);
  return f[l][r][al][ar] = s;
}
int main() {
  cin >> n >> h >> k;
  a[0] = -9999999999;
  a[n + 1] = 9999999999;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(f, 0, sizeof(f));
  sort(a + 1, a + 1 + n);
  ll[1] = 1;
  lr[n] = n;
  for (int i = 2; i <= n; i++) {
    if (a[i] - h < a[i - 1]) {
      ll[i] = ll[i - 1];
    } else
      ll[i] = i;
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] + h > a[i + 1]) {
      lr[i] = lr[i + 1];
    } else
      lr[i] = i;
  }
  printf("%.9lf\n", dfs(1, n, 0, 0));
}
