#include <bits/stdc++.h>
using namespace std;
void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((long long)((s).size())) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
const long long MOD = 1e9 + 7;
const long long MAXN = 2e5 + 1;
const long long INF = 1e18 + 5;
signed main() {
  setIO();
  long long n, q;
  cin >> n >> q;
  set<long long> s;
  for (long long i = 1; i <= n; i++) s.insert(i);
  vector<long long> ans(n + 1);
  while (q--) {
    long long l, r, x;
    cin >> l >> r >> x;
    auto p = s.lower_bound(l);
    while (p != s.end()) {
      if (*p > r) break;
      if (*p != x) {
        ans[*p] = x;
        if (p == s.begin()) {
          s.erase(s.begin());
          p = --s.begin();
          continue;
        }
        auto r = p;
        p--;
        s.erase(r);
      }
      p++;
    }
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
