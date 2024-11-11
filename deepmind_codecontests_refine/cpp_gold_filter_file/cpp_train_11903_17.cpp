#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k;
  cin >> k;
  string a;
  cin >> a;
  long long n = a.size();
  long long dp[n + 1];
  long long prevdp[n + 1];
  for (long long i = 0; i <= n; i++) {
    dp[i] = n;
    prevdp[i] = -1;
  }
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '1') {
      cnt++;
      dp[cnt] = i;
      prevdp[cnt] = i;
    }
  }
  long long orig = cnt;
  if (cnt < k) {
    cout << 0 << endl;
    return;
  }
  long long j = 0;
  long long ansz = 0;
  while (j < n) {
    if (a[j] == '0') {
      long long lth = 0;
      while (j < n && a[j] == '0') {
        j++;
        lth++;
      }
      ansz += (((lth) * (lth + 1)) / 2);
    } else
      j++;
  }
  if (k == 0) {
    cout << ansz << endl;
    return;
  }
  cnt = 0;
  long long i = 0;
  long long ans = 0;
  while (i < n) {
    if (a[i] == '1') {
      cnt++;
      if (orig - cnt >= k - 1) {
        long long pos1 = prevdp[cnt - 1] + 1;
        long long pos2 = dp[cnt + k - 1];
        long long pos3;
        if (cnt + k > n)
          pos3 = n - 1;
        else
          pos3 = dp[cnt + k] - 1;
        ans += ((pos3 - pos2 + 1) * (i - pos1 + 1));
      }
    }
    i++;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
