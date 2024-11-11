#include <bits/stdc++.h>
using namespace std;
double d[100005], ans;
int n, k;
double x, y, a[100005];
double cal1(int l, int r) { return a[r] - a[l] + min(d[l], d[r]); }
double cal2(int l, int r) {
  return a[r] - a[l] + min(d[l] + fabs(a[r] - x), d[r] + fabs(x - a[l]));
}
int main() {
  cout << setprecision(10) << fixed;
  cin >> n >> k;
  for (int i = 1; i <= n + 1; i++) scanf("%lf", &a[i]);
  cin >> y;
  x = a[k];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    d[i] = sqrt((a[i] - a[n + 1]) * (a[i] - a[n + 1]) + y * y);
  if (k == n + 1) {
    ans = a[n] - a[1] + min(d[1], d[n]);
    cout << ans;
    return 0;
  }
  ans = cal2(1, n);
  for (int i = 1; i <= n; i++) {
    ans =
        min(ans, min(cal1(1, i) + cal2(i + 1, n), cal1(i + 1, n) + cal2(1, i)));
  }
  cout << ans;
  return 0;
}
