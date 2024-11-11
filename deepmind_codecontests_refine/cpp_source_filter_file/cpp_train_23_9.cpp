#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a[3], pre[3];
  for (long long i = 0; i < n; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (y & z)
      a[0].push_back(x);
    else if (y)
      a[1].push_back(x);
    else if (x)
      a[2].push_back(x);
  }
  auto get_pref = [&](vector<long long>& x, vector<long long>& y) {
    y.resize(((long long)(x).size()) + 1);
    for (long long i = 0; i < ((long long)(x).size()); i++) {
      y[i + 1] = y[i] + x[i];
    }
  };
  for (long long i = 0; i < 3; i++) {
    sort((a[i]).begin(), (a[i]).end());
    get_pref(a[i], pre[i]);
  }
  long long ans = INF;
  for (long long i = 0; i <= k; i++) {
    if (((long long)(a[0]).size()) >= i &&
        ((long long)(a[1]).size()) >= k - i &&
        ((long long)(a[2]).size()) >= k - i) {
      ans = min(ans, pre[0][i] + pre[1][k - i] + pre[2][k - i]);
    }
  }
  cout << (ans == INF ? -1 : ans);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  while (tt--) {
    solve();
  }
}
