#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
void solve() {
  long long n, k;
  cin >> n >> k;
  long long x = 0, y = 0;
  long long arr[n][n];
  long long cur = 0;
  memset(arr, 0, sizeof(arr));
  while (k) {
    arr[x][y] = 1;
    x = x + 1;
    y = (y + 1) % n;
    if (x == n) {
      x = 0;
      cur++;
      y = cur;
    }
    k--;
  }
  long long mn = (long long)1e9 + 1, mx = -(long long)1e9 + 1;
  for (long long i = 0; i < n; i++) {
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      sum += arr[i][j];
    }
    mn = min(mn, sum);
    mx = max(mx, sum);
  }
  long long ans = 0;
  ans += (mx - mn) * (mx - mn);
  mx = -(long long)1e9 + 1, mn = (long long)1e9 + 1;
  for (long long j = 0; j < n; j++) {
    long long sum = 0;
    for (long long i = 0; i < n; i++) sum += arr[i][j];
    mn = min(mn, sum);
    mx = max(mx, sum);
  }
  ans += (mx - mn) * (mx - mn);
  cout << ans << "\n";
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) cout << arr[i][j];
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
