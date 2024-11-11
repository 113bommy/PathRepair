#include <bits/stdc++.h>
using namespace std;
const long long mxN = (long long)1e5 + 5;
const long long MAX = (long long)1e9 + 9;
long long n, a[mxN];
long long dp[mxN];
long long mx() {
  long long xd = 0, xd1 = 0;
  for (long long i = 0; i < n - 1; i++) {
    xd1 += a[i];
    xd = max(xd1, xd);
    if (xd1 < 0) xd1 = 0;
  }
  xd1 = 0;
  for (long long i = 1; i < n; i++) {
    xd1 += a[i];
    xd = max(xd1, xd);
    if (xd1 < 0) xd1 = 0;
  }
  return xd;
}
void solve() {
  long long sum = 0, cnt = 0, cnt2 = 0;
  ;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] < 0) {
      cnt++;
    } else {
      cnt2++;
    }
  }
  if (cnt == n) {
    cout << "NO\n";
  } else if (cnt2 == n) {
    cout << "YES\n";
  } else {
    if (mx() < sum) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1, i = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
