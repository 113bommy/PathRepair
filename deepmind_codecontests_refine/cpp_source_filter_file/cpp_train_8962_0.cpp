#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")
const long long inf = 0x3f3f3f3f3f3f3f3LL;
const long long mod = (long long)1e9 + 7;
using namespace std;
template <class T, class T2>
void smin(T& a, T2 val) {
  if (a > val) a = val;
}
template <class T, class T2>
void smax(T& a, T2 val) {
  if (a < val) a = val;
}
const long long N = 5 * (long long)1e5 + 10;
long long n, x[N], y[N], m;
vector<long long> v[N];
vector<long long> p;
long long pref_x[N], suff_y[N], ans[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    p.push_back(i);
  }
  for (long long i = 0; i < m; ++i) {
    long long idx1, idx2;
    cin >> idx1 >> idx2;
    long long minn = min(x[idx1] + y[idx2], x[idx2] + y[idx1]);
    ans[idx1] -= minn;
    ans[idx2] -= minn;
  }
  sort(p.begin(), p.end(),
       [&](long long i, long long j) { return x[i] - y[i] < x[j] - y[j]; });
  for (long long i = 1; i <= n; ++i) {
    pref_x[i] = pref_x[i - 1];
    long long idx = p[i - 1];
    pref_x[i] += x[idx];
  }
  for (long long i = n; i >= 1; --i) {
    suff_y[i] = suff_y[i + 1];
    long long idx = p[i - 1];
    suff_y[i] += y[idx];
  }
  for (long long i = 1; i <= n; ++i) {
    long long idx = p[i - 1];
    ans[idx] = suff_y[i + 1] + x[idx] * (n - i);
    ans[idx] += pref_x[i - 1] + y[idx] * (i - 1);
  }
  for (long long i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
