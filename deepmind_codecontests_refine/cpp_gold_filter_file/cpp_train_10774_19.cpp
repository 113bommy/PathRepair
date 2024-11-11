#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, oo = 1e9;
long double a[N], b[N];
int n;
inline long double calc(const long double &x) {
  long double min_pref = 0, mx_pref = 0;
  long double sum = 0;
  long double ans = 0;
  for (int i = 1; i <= n; ++i) {
    sum += a[i] - x;
    min_pref = min(min_pref, sum);
    mx_pref = max(mx_pref, sum);
    ans = max(ans, max(fabs(sum - min_pref), fabs(sum - mx_pref)));
  }
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  long double l = -1e5, r = 1e5;
  for (int cnt = 0; cnt <= 200; ++cnt) {
    long double mid1 = l + (r - l) / 3;
    long double mid2 = r - (r - l) / 3;
    if (calc(mid1) < calc(mid2)) {
      r = mid2;
    } else {
      l = mid1;
    }
  }
  cout.precision(10);
  cout << fixed;
  cout << calc(l);
  return 0;
}
