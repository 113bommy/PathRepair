#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
void usaco(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const long double Pi = acos(-1);
const long long B = 500;
long long n, m, k, s, ans, q, res, a[N];
long long cnt[N], tcnt[N];
vector<pair<long long, long long> > edges[N];
bool check(long long a) {
  while (a) {
    if (a % 10 != 4 && a % 10 != 7) return 0;
    a /= 10;
  }
  return 1;
}
void dfs(long long u, long long p = -1) {
  cnt[u] = 1;
  for (auto x : edges[u]) {
    if (x.first == p) continue;
    dfs(x.first, u), cnt[u] += cnt[x.first];
    tcnt[u] += (x.second ? cnt[x.first] : tcnt[x.first]);
  }
}
void rdfs(long long u, long long up = 0, long long ucnt = 0, long long p = -1) {
  res += (tcnt[u] + up) * (tcnt[u] + up - 1);
  for (auto x : edges[u]) {
    if (x.first == p) continue;
    rdfs(x.first,
         (x.second ? ucnt + cnt[u] - cnt[x.first]
                   : up + tcnt[u] - tcnt[x.first]),
         ucnt + cnt[u] - cnt[x.first], u);
  }
}
void solve(long long t_case) {
  cin >> n;
  for (long long i = 1, a, b, c, x; i < n; i++) {
    cin >> a >> b >> c, x = check(c);
    edges[a].push_back({b, x}), edges[b].push_back({a, x});
  }
  dfs(1);
  rdfs(1);
  cout << res << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (!0) {
    solve(1);
  } else {
    long long t;
    cin >> t;
    for (long long t_case = 1; t_case <= t; t_case++) solve(t_case);
  }
  return 0;
}
