#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const long long INFll = 1000000000000000000ll;
const int MOD = 1000000007;
const long double EPS = 0.0000001;
int n, m;
int a[200500];
long double s;
inline long double getMin(long double x) {
  long double ret = 0, t = 0;
  long double mn, mx;
  s = 0;
  mn = 0;
  mx = -INFll;
  for (int i = 0; i < n; ++i) {
    s += a[i] - x;
    mx = max(mx, s - mn);
    mn = min(s, mn);
  }
  mx = abs(mx);
  return mx;
}
inline long double getMax(long double x) {
  long double ret = 0, t = 0;
  long double mn, mx;
  s = 0;
  mn = INFll;
  mx = 0;
  for (int i = 0; i < n; ++i) {
    s += a[i] - x;
    mn = min(mn, s - mx);
    mx = max(mx, s);
  }
  mn = abs(mn);
  return mn;
}
inline long double get(long double x) { return max(getMin(x), getMax(x)); }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long double l = -10000;
  long double r = 10000;
  while (r - l > 5 * EPS) {
    long double m1 = l + (r - l) / 3.;
    long double m2 = r - (r - l) / 3.;
    long double f1 = get(m1);
    long double f2 = get(m2);
    if (f1 > f2) {
      l = m1;
    } else {
      r = m2;
    }
  }
  long double ans = INFll;
  while (l <= r) {
    ans = min(ans, get(l));
    l += EPS;
  }
  cout << fixed << setprecision(6) << ans << endl;
  return 0;
}
