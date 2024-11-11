#include <bits/stdc++.h>
using namespace std;
double a[1003], b[1003], m;
int n;
bool p(long double ans) {
  int t = 1;
  for (int i = 1; i <= n; i++) {
    if (ans <= ((ans + m) / a[i])) return false;
    ans -= ((ans + m) / (long double)a[i]);
    if (i == n)
      t = 1;
    else
      t = i + 1;
    if (ans < ((ans + m) / b[t])) return false;
    ans -= ((ans + m) / b[t]);
  }
  if (ans >= 0.0) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int flag = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  long double lo = 0.0, hi = 1000000000.0 + 1.0;
  for (int i = 0; i <= 300; i++) {
    long double mid = lo + (hi - lo) / 2.0;
    if (p(mid) == true)
      hi = mid, flag = 1;
    else
      lo = mid;
  }
  if (hi == 1e9 + 1.0 and flag == 1)
    cout << -1 << endl;
  else
    cout << fixed << setprecision(10) << lo << endl;
}
