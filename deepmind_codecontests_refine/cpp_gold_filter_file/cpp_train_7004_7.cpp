#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  int t;
  cin >> t;
  int c = t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k), index(n + 1), next(n + 1);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    for (int i = 0; i < n; i++) index[a[i]] = i;
    for (int i : b) next[i] = 1;
    int ans = 1;
    for (int i = 0; i < k; i++) {
      int ti = index[b[i]];
      int cur_num = 0;
      if (ti > 0) cur_num += !next[a[ti - 1]];
      if (ti < n - 1) cur_num += !next[a[ti + 1]];
      next[a[ti]] = 0;
      ans *= cur_num;
      ans %= mod;
    }
    cout << ans << endl;
  }
  cin >> t;
}
