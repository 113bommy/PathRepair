#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ii = pair<long long, long long>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vec = vector<long long>;
using vecc = vector<vector<long long> >;
namespace royyaha {
template <typename T>
void pr(const T& x) {
  cout << x;
}
template <typename T1, typename T2>
void pr(const pair<T1, T2>& x) {
  cout << x.first << " " << x.second;
}
template <typename T, typename... Args>
void pr(const T& x, const Args&... rest) {
  pr(x);
  pr(rest...);
}
template <typename T>
void ou(const T& x) {
  pr(x);
  cout << endl;
}
template <typename T, typename... Args>
void ou(const T& x, const Args&... rest) {
  pr(x, ' ');
  ou(rest...);
}
template <typename T>
void ou(const vector<T>& v, long long n = 0) {
  n = (n ? n : v.size());
  for (auto it = v.begin(); it != v.begin() + n; ++it) {
    if (it + 1 == v.end())
      ou(*it);
    else
      pr(*it, ' ');
  }
}
}  // namespace royyaha
using namespace royyaha;
bool intersection(ii a, ii b) {
  return !(a.first > b.second || a.second < b.first);
}
const long long maxn = 2e5 + 50;
vec depth(maxn);
vec son(maxn);
vec e[maxn];
void dfs(long long u, long long pre) {
  depth[u] = depth[pre] + 1;
  son[u] = 1;
  for (auto v : e[u])
    if (v != pre) {
      dfs(v, u);
      son[u] += son[v];
    }
}
signed main() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n - 1; ++i) {
    long long u, v;
    cin >> u >> v;
    u--, v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(0, 0);
  vec f(n);
  for (long long i = 0; i < n; ++i) f[i] = depth[i] - son[i];
  sort(f.begin(), f.end());
  reverse(f.begin(), f.end());
  cout << accumulate(f.begin(), f.begin() + k, 0) << endl;
}
