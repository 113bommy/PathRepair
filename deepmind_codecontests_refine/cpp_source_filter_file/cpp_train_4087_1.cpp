#include <bits/stdc++.h>
using namespace std;
const long long N = 300010;
const double eps = 1e-9;
const double pi = 4 * atan(1);
long long t, n, m, a[N], res[N];
vector<long long> adj[N];
vector<pair<long long, long long> > p;
int solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p.push_back({a[i], i});
  }
  sort(p.begin(), p.end());
  for (auto u : p) {
    long long x = u.second, val = u.first;
    vector<long long> v;
    for (auto k : adj[x]) {
      if (res[k]) {
        v.push_back(res[k]);
      }
    }
    sort(v.begin(), v.end());
    long long mex = 1;
    for (auto k : v) {
      if (k == mex) mex++;
    }
    if (mex != val) {
      printf("-1\n");
      return 0;
    }
    res[x] = mex;
  }
  for (auto u : p) {
    long long x = u.second, val = u.first;
    printf("%lld ", x);
  }
  return 0;
}
int main() { return solve(); }
