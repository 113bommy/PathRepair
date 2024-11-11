#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> a[i];
    vector<string> s(n);
    for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> s[i];
    long long maxi = 0;
    vector<long long> res(m);
    for (int i = 0, ggdem = (1ll << n); i < ggdem; ++i) {
      vector<pair<long long, long long>> c(m);
      for (int j = 0, ggdem = n; j < ggdem; ++j) {
        long long p = 1;
        if (i & (1ll << j)) p = -1;
        for (int ii = 0, ggdem = m; ii < ggdem; ++ii) {
          if (s[j][ii] == '1') c[ii].first += p;
        }
      }
      for (int ii = 0, ggdem = m; ii < ggdem; ++ii) c[ii].second = ii;
      sort(c.begin(), c.end());
      long long val = 0;
      for (int ii = 0, ggdem = m; ii < ggdem; ++ii)
        val += (ii + 1) * c[ii].first;
      for (int j = 0, ggdem = n; j < ggdem; ++j) {
        if (i & (1ll << j))
          val += a[j];
        else
          val -= a[j];
      }
      if (val > maxi) {
        maxi = val;
        for (int ii = 0, ggdem = m; ii < ggdem; ++ii) res[c[ii].second] = ii;
      }
    }
    for (auto i : res) cout << i + 1 << " ";
    cout << "\n";
  }
  return 0;
}
