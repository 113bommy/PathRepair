#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long a[N], u;
int n;
long double solve() {
  long double ans = -1;
  for (int i = 1; i <= n - 2; i++) {
    long double ei = (long double)a[i], ej = (long double)a[i + 1];
    int idx = -1;
    int l = i + 2, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if ((a[mid] - a[i]) <= u)
        l = mid + 1, idx = mid;
      else
        r = mid - 1;
    }
    if (idx != -1) {
      long double ek = (long double)a[idx];
      long double val = (ek - ej) / (ek - ei);
      ans = max(ans, val);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> u;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long double ans = solve();
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
