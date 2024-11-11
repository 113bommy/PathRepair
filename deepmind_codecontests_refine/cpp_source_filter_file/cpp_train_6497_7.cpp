#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)(1e3) + 100;
const long long INF = (long long)(1e9);
const double PI = acos(-1.0);
const double EPS = (1e-6);
int n, k, a[MAXN], d[MAXN];
bool check(long long val) {
  for (int i = 1; i <= n; i++) d[i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (abs(a[i] - a[j]) <= 1ll * (j - i) * val) d[j] = max(d[j], d[i] + 1);
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, d[i] + 1);
  return ((n - res) <= k);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long l = 0, r = 2 * INF, ans = 2 * INF;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans;
  return 0;
}
