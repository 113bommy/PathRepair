#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long cp[200010];
long long find(long long x) { return cp[x] = cp[x] == x ? x : find(cp[x]); }
void union_(long long x, long long y) { cp[find(x)] = find(y); }
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (long long j = 0; j < 20010; ++j) cp[j] = j;
  long long m, n;
  cin >> m >> n;
  vector<long long> A(m);
  vector<long long> B(n);
  for (long long i = 0; i < m; ++i) cin >> A[i];
  for (long long i = 0; i < n; ++i) cin >> B[i];
  vector<pair<long long, pair<long long, long long>>> edg;
  for (long long u = 0; u < m; ++u) {
    long long s;
    cin >> s;
    for (long long i = 0; i < s; ++i) {
      long long v;
      cin >> v;
      edg.push_back({B[v - 1] + A[u], {u, v - 1ll}});
    }
  }
  sort((edg).begin(), (edg).end());
  reverse((edg).begin(), (edg).end());
  long long ans = 0;
  for (long long k = 0; k < edg.size(); ++k) {
    long long u = edg[k].second.first, v = edg[k].second.second + m;
    if (find(u) == find(v)) {
      ans += edg[k].first;
    } else {
      union_(u, v);
    }
  }
  cout << ans << "\n";
}
