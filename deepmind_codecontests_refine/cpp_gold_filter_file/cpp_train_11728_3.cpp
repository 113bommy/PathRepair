#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 36;
const long long M = 5e2 + 36;
const long long INF = 2e9 + 7;
const long long MOD = 987654323;
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int XK[4] = {-1, 0, 1, 0};
const int YK[4] = {0, -1, 0, 1};
const int X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int n, d, b;
int a[N], c[N];
int solve() {
  for (int i(0); i < n; ++i) {
    c[i] = 0;
  }
  int ans = 0;
  for (int i(0); i < n; ++i) {
    int l = 0, r = i, ans = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int mve = max(((i - mid + d - 1) / d) - 1, 0);
      if (mid >= mve) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
    c[ans] += a[i];
  }
  for (int i(0); i < n; ++i) {
    if (c[i] < b) {
      ans++;
      c[i + 1] += c[i];
    } else {
      c[i + 1] += c[i] - b;
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d >> b;
  for (int i(0); i < n; ++i) {
    cin >> a[i];
  }
  int ans = solve();
  reverse(a, a + n);
  ans = max(ans, solve());
  cout << ans << endl;
  return 0;
}
