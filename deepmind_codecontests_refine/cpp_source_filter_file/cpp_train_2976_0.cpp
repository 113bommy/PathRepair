#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long double a[maxn];
long double b[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long double p;
  cin >> n >> p;
  cout << setprecision(12) << fixed;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  long double l = 0, r = 1e16 + 7;
  for (int s = 0; s < 200; s++) {
    long double t = (l + r) / 2;
    long double ans = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i] - t * a[i] >= 0) continue;
      ans += (t * a[i] - b[i]) / p;
    }
    if (ans <= t)
      l = t;
    else
      r = t;
  }
  if (l >= 1e16) {
    cout << -1 << endl;
    return 0;
  }
  cout << l << endl;
}
