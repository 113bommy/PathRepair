#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 1;
const int N = 300101;
long long a[N], b[N], dp[N][5];
int visi[N][5], passed = 1, n;
long long solve(int p, int k) {
  if (p == n) return 0;
  long long &ans = dp[p][k];
  int &vis = visi[p][k];
  if (vis == passed) return ans;
  vis = passed;
  ans = inf;
  if (p == 0 || (a[p] + 1) != (a[p - 1] + k))
    ans = min(b[p] + solve(p + 1, 1), ans);
  if (p == 0 || (a[p] + 2) != (a[p - 1] + k))
    ans = min(2 * b[p] + solve(p + 1, 2), ans);
  if (p == 0 || a[p] != (a[p - 1] + k)) {
    ans = min(ans, solve(p + 1, 0));
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    a[n] = -1;
    cout << solve(0, 0) << "\n";
    passed++;
  }
  return 0;
}
