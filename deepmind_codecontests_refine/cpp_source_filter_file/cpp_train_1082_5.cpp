#include <bits/stdc++.h>
using namespace std;
long long h[100002], p[100002];
int n, m;
long long fabs(long long x) {
  if (x < 0) x = -x;
  return x;
}
int need(long long use) {
  int j = 1;
  long long tot = 0;
  for (int i = 1; i <= n; i++) {
    int low = j, high = m, ans = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      long long minval = min(p[mid] - p[j] + fabs(h[i] - p[mid]),
                             p[mid] - p[j] + fabs(h[i] - p[j]));
      if (minval <= use)
        ans = mid, low = mid + 1;
      else
        high = mid - 1;
    }
    if (ans == -1) return 0;
    if (ans == m) return 1;
    j = ans + 1;
  }
  if (j <= m) return 0;
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> h[i];
  for (int i = 1; i <= m; i++) cin >> p[i];
  long long low = 0;
  long long high = 2 * 1e10;
  long long ans = 0;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (need(mid) == 1)
      ans = mid, high = mid - 1;
    else
      low = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
