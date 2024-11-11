#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const double pi = 3.141592653589793238;
const long long inf = 100000000000000000;
void pv(vector<long long> v) {
  for (long long i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}
void pa(long long a[], long long n, long long p) {
  for (long long i = p; i < n + p; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}
long long modexp(long long x, long long y) {
  long long res = 1;
  x = x % 998244353;
  while (y > 0) {
    if (y & 1LL) res = (res * x) % 998244353;
    y = y >> 1;
    x = (x * x) % 998244353;
  }
  return res;
}
long long invmod(long long a) { return modexp(a, 998244353 - 2); }
vector<long long> edge[1000005];
void ipgraph(long long n, long long m) {
  for (long long i = 1; i <= n; i += 1) edge[i].clear();
  if (m == 0) return;
  for (long long i = 1; i <= m; i += 1) {
    long long a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
}
std::vector<long long> v;
unordered_map<long long, std::vector<long long>> fac;
void findFactor(long long a) {
  if (fac[a].size()) return;
  for (long long i = 1; i <= sqrt(a); i += 1) {
    if (a % i == 0) {
      fac[a].push_back(i);
      if (a / i != i) {
        fac[a].push_back(a / i);
      }
    }
  }
  sort(fac[a].begin(), fac[a].end());
  for (long long u : fac[a]) findFactor(u);
}
void dfs(long long a, long long k) {
  if (v.size() >= 100000) return;
  if (k == 0 || a == 1) {
    v.push_back(a);
    return;
  }
  for (long long u : fac[a]) {
    dfs(u, k - 1);
  }
}
void solve() {
  long long x, k;
  cin >> x >> k;
  findFactor(x);
  dfs(x, min(k, 100000LL));
  pv(v);
}
int32_t main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i += 1) {
    solve();
  }
}
