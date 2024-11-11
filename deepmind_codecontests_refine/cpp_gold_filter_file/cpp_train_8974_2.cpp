#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  long long a[200005], cnt1[100005][2], cnt2[100005][2];
  cin >> n;
  for (long long i = 0; i < 2 * n; i++) cin >> a[i];
  cnt1[0][0] = (a[0] == 1 ? 1 : 0);
  cnt1[0][1] = (a[0] == 2 ? 1 : 0);
  for (long long i = 1; i <= n - 1; i++) {
    cnt1[i][0] = cnt1[i - 1][0] + (a[i] == 1 ? 1 : 0);
    cnt1[i][1] = cnt1[i - 1][1] + (a[i] == 2 ? 1 : 0);
  }
  cnt2[n - 1][0] = (a[2 * n - 1] == 1 ? 1 : 0);
  cnt2[n - 1][1] = (a[2 * n - 1] == 2 ? 1 : 0);
  for (long long i = 2 * n - 2; i >= n; i--) {
    cnt2[i - n][0] = cnt2[i + 1 - n][0] + (a[i] == 1 ? 1 : 0);
    cnt2[i - n][1] = cnt2[i + 1 - n][1] + (a[i] == 2 ? 1 : 0);
  }
  unordered_map<long long, long long> m;
  long long ans = INT_MAX;
  long long sc = 2 * n;
  for (long long i = 0; i < n; i++) {
    m[cnt1[i][0] - cnt1[i][1]] = i + 1;
    if (cnt1[i][0] - cnt1[i][1] == 0) sc = min(sc, 2 * n - i - 1);
  }
  for (long long i = 0; i < n; i++) {
    if (m.count(cnt2[i][1] - cnt2[i][0]))
      ans = min(ans, n - m[cnt2[i][1] - cnt2[i][0]] + i);
    if (cnt2[i][0] - cnt2[i][1] == 0) sc = min(sc, n + i);
  }
  cout << min(ans, sc) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
