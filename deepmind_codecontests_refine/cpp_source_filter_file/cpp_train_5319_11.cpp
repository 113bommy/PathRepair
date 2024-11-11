#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 5;
const int inf = (int)1e9 + 9;
int n, m;
int a[N], b[N];
int ok(long double x) {
  for (int i = 1; i <= n; ++i) {
    int nxt = (i == n ? 1 : i + 1);
    if (x * a[i] < (x + m)) {
      return 0;
    }
    x -= (x + m) / a[i];
    if (x * b[nxt] < (x + m)) {
      return 0;
    }
    x -= (x + m) / b[nxt];
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  long double lf = 0, rg = 1e9;
  if (!ok(rg)) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= 200; ++i) {
    long double mid = (lf + rg) / 2.0;
    if (ok(mid)) {
      rg = mid;
    } else {
      lf = mid;
    }
  }
  cout << fixed << setprecision(11) << (lf + rg) / 2.0;
  return 0;
}
