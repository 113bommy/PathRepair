#include <bits/stdc++.h>
using namespace std;
long long const N = 1e5 + 10;
vector<long long> a[N];
long long r[N], c[N], ans, n, m;
vector<pair<pair<long long, long long>, long long>> vec, nv;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      r[i] += a[i][j];
      c[j] += a[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    vec.push_back({{r[i], i}, 0});
  }
  for (long long i = 0; i < m; i++) {
    vec.push_back({{c[i], i}, 1});
  }
  sort(vec.begin(), vec.end());
  for (long long i = vec.size() - 1; i >= 0 && nv.size() < 8; i--) {
    nv.push_back(vec[i]);
  }
  long long sz = nv.size();
  for (long long mask = 0; mask < (1 << sz); mask++) {
    long long res = 0;
    vector<long long> rows, cols;
    if (__builtin_popcount(mask) > 4) continue;
    for (long long i = 0; i < sz; i++) {
      if (mask & (1 << i)) {
        res += nv[i].first.first;
        if (nv[i].second) {
          cols.push_back(nv[i].first.second);
        } else {
          rows.push_back(nv[i].first.second);
        }
      }
    }
    for (long long r : rows) {
      for (long long c : cols) {
        res -= a[r][c];
      }
    }
    ans = max(ans, res);
  }
  cout << ans << '\n';
}
