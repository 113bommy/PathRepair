#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7, inf = 0x3f3f3f3f, mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pos(n), b(k), need(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i], a[i]--, pos[a[i]] = i;
    for (int i = 0; i < k; ++i) {
      cin >> b[i];
      b[i]--;
      need[b[i]] = 1;
    }
    long long ans = 1;
    for (int i = 0; i < k; ++i) {
      int p = pos[b[i]];
      long long tmp = 0;
      if (p + 1 < n) {
        if (!need[a[p + 1]]) tmp++;
      }
      if (p - 1 >= 0) {
        if (!need[a[p - 1]]) tmp++;
      }
      ans = ans * tmp % mod;
      need[b[i]] = 0;
    }
    cout << ans << '\n';
  }
  return 0;
}
