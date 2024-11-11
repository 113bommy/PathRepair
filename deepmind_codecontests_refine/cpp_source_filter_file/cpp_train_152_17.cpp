#include <bits/stdc++.h>
using namespace std;
int n, a[200001];
long double b[200001], pre[200001], ans = 2e11;
long double check(long double x) {
  for (int i = 1; i <= n; i++) b[i] = a[i] - x;
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + b[i];
  long double mn = 2e11, mx = -2e11;
  long double mns = 0, mxs = 0;
  for (int i = 1; i <= n; i++) {
    mn = min(mn, pre[i] - mxs);
    mx = max(mx, pre[i] - mns);
    mns = min(mns, pre[i]);
    mxs = max(mxs, pre[i]);
  }
  return max(-mn, mx);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long double low = -1e6, high = 1e6;
  for (int i = 0; i <= 100; i++) {
    long double med = (low + high) / 2;
    long double x = check(med);
    long double y = check(med + 1e-7);
    ans = min(ans, min(x, y));
    if (x < y)
      high = med;
    else
      low = med + 1e-7;
  }
  cout << fixed << setprecision(8) << ans << '\n';
}
