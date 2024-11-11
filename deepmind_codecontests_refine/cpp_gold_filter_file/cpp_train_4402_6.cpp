#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<long long> > groups;
  groups.push_back(a);
  long long x = 0;
  long long inv = 0;
  for (long long i = 30; i >= 0; i--) {
    long long zero = 0, one = 0;
    vector<vector<long long> > ngroups;
    for (const vector<long long> &group : groups) {
      long long t_inv = 0;
      long long n_inv = 0;
      long long sz = group.size();
      long long invs = (sz * (sz - 1)) / 2;
      long long bi = 0;
      long long nbi = 0;
      vector<long long> g0, g1;
      for (auto el : group) {
        if (el & (1ll << i)) {
          bi++;
          n_inv += nbi;
          g1.push_back(el);
        } else {
          nbi++;
          t_inv += bi;
          g0.push_back(el);
        }
      }
      if (!g0.empty()) ngroups.push_back(g0);
      if (!g1.empty()) ngroups.push_back(g1);
      zero += t_inv;
      one += n_inv;
    }
    if (zero > one) x |= (1ll << i);
    inv += min(one, zero);
    groups = ngroups;
  }
  cout << inv << ' ' << x << '\n';
}
