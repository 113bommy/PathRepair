#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long ans[m + 1];
    memset(ans, 0, sizeof ans);
    map<long long, long long> f;
    long long a[n], x;
    for (long long i = 0; i < n; i++) {
      cin >> x;
      f[x]++;
      a[i] = x;
    }
    for (auto var : f) {
      long long x = var.first, y = var.second;
      for (long long i = x; i <= m; i += x) ans[i] += y;
    }
    long long mx = 0, k = 0;
    for (long long i = 1; i <= m; i++) {
      if (ans[i] > k) {
        mx = i;
        k = ans[i];
      }
    }
    cout << mx << " " << k << '\n';
    for (long long i = 0; i < n; i++) {
      if (mx % a[i] == 0) cout << i + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}
