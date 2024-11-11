#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long testcase;
  cin >> testcase;
  while (testcase--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> per(n), vis(k), indx(n + 1), vismark(n + 1);
    for (long long i = 0; i < n; i++) {
      cin >> per[i];
      indx[per[i]] = i;
    }
    for (long long i = 0; i < k; i++) {
      cin >> vis[i];
      vismark[vis[i]] = 1;
    }
    long long ans = 1;
    for (long long i = 0; i < k; i++) {
      long long count = 0;
      long long j = indx[vis[i]];
      if (j != 0) count += (vismark[per[j - 1]] == 0);
      if (j != n - 1) count += (vismark[per[j + 1]] == 0);
      ans *= count % 998244353;
      vismark[vis[i]] = 0;
    }
    cout << ans << "\n";
  }
  return 0;
}
