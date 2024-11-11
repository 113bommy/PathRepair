#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
  ;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long POSITIVE_INFINITY = 9223372036854775807;
const long long NEGATIVE_INFINITY = -9223372036854775807;
const long double PI = acos(-1.0);
const long long MOD = 1000000007;
const long long INF = 1e18;
const long long N = 1e6 + 5;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  vector<vector<long long>> idxs(n);
  for (long long i = 0; i < n; ++i)
    cin >> v[i], --v[i], idxs[v[i]].push_back(i);
  vector<long long> ans(n + 2, INF);
  for (long long i = 0; i < n; i++) {
    long long start = -1;
    long long mx = 0;
    for (auto idx : idxs[i]) {
      mx = max(mx, idx - start);
      start = i;
    }
    mx = max(mx, n - start);
    ans[mx] = min(ans[mx], i);
  }
  long long mn = INF;
  for (long long i = 1; i <= n; i++) {
    mn = min(mn, ans[i]);
    if (mn == INF) {
      cout << -1 << " ";
    } else {
      cout << mn + 1 << " ";
    }
  }
  cout << '\n';
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
