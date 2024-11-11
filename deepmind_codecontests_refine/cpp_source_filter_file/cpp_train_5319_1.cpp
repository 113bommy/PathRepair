#include <bits/stdc++.h>
using namespace std;
double a[1003], b[1003], m;
int n;
bool ck(double f) {
  f += m;
  for (int i = 1; i <= n; i++) {
    double fx = f / a[i - 1];
    f -= fx;
    if (f < 0) return false;
    fx = f / b[i];
    f -= fx;
    if (f < 0) return false;
  }
  return f >= m;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  a[n] = a[0];
  b[n] = b[0];
  double lo = 0, hi = 1e9, mid, ans;
  bool fl = false;
  int cc = 1000;
  while (cc--) {
    mid = (hi + lo) / 2;
    if (ck(mid)) {
      fl = true;
      hi = mid;
      ans = mid;
    } else {
      lo = mid;
    }
  }
  if (fl) {
    cout << fixed << setprecision(7) << ans << endl;
  } else {
    printf("-1\n");
  }
  return 0;
}
