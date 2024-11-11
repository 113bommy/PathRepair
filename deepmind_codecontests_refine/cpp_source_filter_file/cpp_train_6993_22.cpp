#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long mxN = 1e6 + 1;
void fileio() {}
const long long N = 2e5 + 1;
void solve() {
  long long n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> l(N, -1), r(N, -1);
  for (long long i = 0; i < n; i++) {
    if (l[a[i]] == -1) l[a[i]] = i;
    r[a[i]] = i;
  }
  vector<pair<long long, long long> > v;
  for (long long i = 1; i < N; i++) {
    if (l[i] != -1) v.push_back({l[i], r[i]});
  }
  sort(v.begin(), v.end());
  ;
  long long p = 0, mxr = 0;
  long long ans = 0;
  for (long long i = 0; i < v.size(); i++) {
    long long l = v[i].first, r = v[i].second;
    if (l > mxr) {
      map<long long, long long> m;
      for (long long j = p; j < mxr + 1; j++) m[a[j]]++;
      long long k = mxr + 1 - p;
      long long c = k;
      for (auto x : m) c = min(c, k - x.second);
      ans += c;
      p = l, mxr = l;
    } else
      mxr = max(mxr, r);
  }
  map<long long, long long> m;
  for (long long j = p; j < mxr + 1; j++) m[a[j]]++;
  long long k = mxr + 1 - p;
  long long c = k;
  for (auto x : m) c = min(c, k - x.second);
  ans += c;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fileio();
  solve();
}
