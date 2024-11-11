#include <bits/stdc++.h>
using namespace std;
const long long int Mod = (long long int)1e9 + 7;
long long int CaseN = 1;
const long double PI = 22 / 7.0;
long long int tst() {
  long long int ans = 0;
  return ans;
}
void solve() {
  long long int n;
  cin >> n;
  long long int p[202][n + 1];
  for (long long int i = 1; i <= 200; i++) {
    memset(p[i], 0, sizeof(p[i]));
  }
  vector<long long int> occ(201, 0);
  for (long long int i = 1; i <= n; i++) {
    long long int a;
    cin >> a;
    occ[a]++;
    p[a][occ[a]] = i;
  }
  long long int ans = 0;
  for (long long int i = 1; i <= 200; i++) {
    long long int k = occ[i];
    for (long long int j = 1; j <= k / 2; j++) {
      long long int l = p[i][j] + 1;
      long long int r = p[i][k - j + 1] - 1;
      long long int cnt1 = j * 2;
      long long int cnt2 = 0;
      if (l <= r) {
        for (long long int o = 1; o <= 200; o++) {
          long long int in1 =
              upper_bound(p[o] + 1, p[o] + 1 + occ[o], r) - 1 - p[o];
          long long int in2 =
              lower_bound(p[o] + 1, p[o] + 1 + occ[o], l) - p[o];
          cnt2 = max(cnt2, in1 - in2 + 1);
        }
      }
      ans = max(ans, (cnt1 + cnt2));
    }
  }
  if (n <= 2) {
    ans = 1;
  }
  cout << ans << endl;
  CaseN++;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
