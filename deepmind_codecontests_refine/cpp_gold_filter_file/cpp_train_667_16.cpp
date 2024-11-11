#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const double err = 0.00000000001;
double a[maxn], b[maxn];
int n, v;
bool zero(double x, double y) {
  if (x > y) swap(x, y);
  if (y - x < err)
    return true;
  else
    return false;
}
double bs(double l, double r) {
  if (zero(l, r)) return l;
  double mid = (l + r) / 2;
  bool ok = true;
  for (int i = 0; i < n; i++)
    if (mid * a[i] > b[i]) ok = false;
  if (ok)
    return bs(mid, r);
  else
    return bs(l, mid);
}
int main() {
  cin >> n >> v;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < n; j++) cin >> b[j];
  double cur = bs(0, v);
  double ans = 0;
  for (int i = 0; i < n; i++) ans += cur * a[i];
  if (ans > v) ans = v;
  cout << fixed << showpoint << setprecision(4) << ans << endl;
  return 0;
}
