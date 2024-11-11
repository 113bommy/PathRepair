#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 9;
int n;
long double m;
long double a[MX], b[MX];
bool check(long double mid) {
  for (int i = 0; i < n; i++) {
    if (i) {
      if (((m + mid) / b[i]) > mid) return 0;
      mid -= ((m + mid) / b[i]);
    }
    if (((m + mid) / a[i]) > mid) return 0;
    mid -= ((m + mid) / a[i]);
  }
  if (((m + mid) / b[0]) > mid) return 0;
  return 1;
}
long double bn(long double l, long double r) {
  long double ans = -1;
  while (r - l >= 1e-8) {
    long double mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1e-8;
    } else
      l = mid + 1e-8;
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  long double x = bn(1, 1e9);
  if (x == -1)
    puts("-1");
  else
    cout << setprecision(6) << fixed << x << endl;
}
