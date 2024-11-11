#include <bits/stdc++.h>
using namespace std;
long long tt, res;
long long calc(long long a, long long b, long long c) {
  return (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> tt;
  while (tt--) {
    res = 9e18;
    long long na, nb, nc;
    cin >> na >> nb >> nc;
    vector<long long> a(na, 0), b(nb, 0), c(nc, 0);
    for (int i = 0; i < na; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < nb; ++i) {
      cin >> b[i];
    }
    for (int i = 0; i < nc; ++i) {
      cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<vector<long long>> adj, radj;
    adj.push_back(a);
    adj.push_back(b);
    adj.push_back(c);
    radj.push_back(a);
    radj.push_back(b);
    radj.push_back(c);
    for (int i = 0; i < 3; ++i) {
      reverse(radj[i].begin(), radj[i].end());
    }
    vector<int> p = {0, 1, 2};
    do {
      for (auto i : adj[p[1]]) {
        auto it1 = lower_bound(adj[p[2]].begin(), adj[p[2]].end(), i);
        auto it2 = lower_bound(radj[p[0]].begin(), adj[p[0]].end(), i,
                               greater<long long>());
        if (it1 != adj[p[2]].end() && it2 != radj[p[0]].end()) {
          res = min(res, calc(*it1, i, *it2));
        }
      }
    } while (next_permutation(p.begin(), p.end()));
    cout << res << "\n";
  }
  return 0;
}
