#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, a[N], b[N];
bool ok;
long double check(long double fuel) {
  long double now = m + fuel;
  for (int i = 1; i < n; ++i) {
    long double rem = now / a[i];
    fuel -= rem;
    now -= rem;
    rem = now / b[i + 1];
    fuel -= rem;
    now -= rem;
  }
  long double rem = now / a[n];
  fuel -= rem;
  now -= rem;
  rem = now / b[1];
  fuel -= rem;
  now -= rem;
  return fuel;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  long double l = 0, r = 1000000000;
  while (1) {
    long double val1 = (2 * l + r) / 3, val2 = (l + 2 * r) / 3;
    if (val2 - val1 <= 1e-9) break;
    long double ans1 = check(val1), ans2 = check(val2);
    if (ans1 < 0)
      l = val1;
    else if (ans2 < 0)
      r = val2;
    else {
      ok = 1;
      if (ans1 < ans2)
        r = val2;
      else
        l = val1;
    }
  }
  if (!ok) return cout << -1, 0;
  cout << fixed << setprecision(10) << (2 * l + r) / 3;
  return 0;
}
