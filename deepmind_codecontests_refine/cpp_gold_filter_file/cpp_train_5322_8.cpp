#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, h;
  cin >> n >> m >> h;
  long long int a[m + 1];
  long long int tot = 0;
  for (long long int i = 1; i <= m; i++) {
    cin >> a[i];
    tot += a[i];
  }
  if (tot < n) {
    cout << -1 << "\n";
    return;
  }
  long double n1 = 1;
  long double d1 = 1;
  for (long long int i = 0; i <= n - 2; i++) {
    n1 *= (tot - a[h] - i);
  }
  for (long long int i = 1; i <= n - 1; i++) {
    d1 *= (tot - i);
  }
  long double p1 = (n1 / d1);
  long double ans = 1 - p1;
  cout << fixed << setprecision(18);
  ;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t, q;
  q = 1;
  for (t = 1; t <= q; t++) {
    solve();
  }
}
