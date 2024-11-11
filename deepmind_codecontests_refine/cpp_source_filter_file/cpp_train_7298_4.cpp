#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 1;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, x[N], y[N];
int neg, pos;
bool check(double r) {
  double mx = -1e12, mn = 1e12;
  for (long long i = 1; i <= n; i++) {
    if (abs(y[i] - r) > r) return 0;
    double d = sqrt((2 * r - y[i]) * y[i]);
    mx = max(mx, x[i] - d);
    mn = min(mn, x[i] + d);
  }
  return mx <= mn;
}
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    if (y[i] < 0) neg = 1;
    if (y[i] > 0) pos = 1;
    y[i] = abs(y[i]);
  }
  if (pos && neg) {
    cout << -1;
    exit(0);
  }
  double l = 0, r = 1e12 + 123;
  for (long long it = 1; it <= 100; it++) {
    double mid = (l + r) / 2.l;
    if (check(mid)) {
      r = mid;
    } else
      l = mid;
  }
  if (check(r)) {
    cout << fixed << setprecision(7) << r;
  } else
    cout << -1;
  return 0;
}
