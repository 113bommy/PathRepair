#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct str {
  long long nxt = -1, prv = -1, av = 0;
};
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<str> a(n + 2);
    vector<long long> mp(n + 1), b(k);
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      mp[x] = i;
      a[i].nxt = i + 1;
      a[i].prv = i - 1;
      a[i].av = 1;
    }
    long long ans = 1;
    for (auto &x : b) {
      cin >> x;
      a[mp[x]].av = 0;
    }
    for (auto x : b) {
      a[mp[x]].av = 1;
      long long cnt = a[a[mp[x]].nxt].av + a[a[mp[x]].prv].av;
      ans = (ans * cnt) % MOD;
      if (a[a[mp[x]].nxt].av) {
        a[mp[x]].nxt = a[a[mp[x]].nxt].nxt;
        a[a[mp[x]].nxt].prv = mp[x];
      } else if (a[a[mp[x]].prv].av) {
        a[mp[x]].prv = a[a[mp[x]].prv].prv;
        a[a[mp[x]].prv].nxt = mp[x];
      }
    }
    cout << ans << endl;
  }
}
