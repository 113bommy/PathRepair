#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize 03
#pragma GCC optimize("unroll-loops")
using namespace std;
inline int cnt1(int x) { return __builtin_popcount(x); }
inline int cnt1(long long x) { return __builtin_popcountll(x); }
long long fact(long long n) { return n == 0 ? 1LL : n * fact(n - 1); }
int fact(int n, int p) { return n == 0 ? 1LL : n * 1LL * fact(n - 1) % p; }
int pow(int a, int n, int p) {
  if (n == 0) return 1;
  long long t = pow(a, n >> 1, p);
  return t * t % p * (n & 1 ? a : 1) % p;
}
inline int inve(int x, int p) { return pow(x, p - 2, p); }
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
istream& operator>>(istream& stream, vector<T>& v) {
  for (long long i = 0; i < (long long)v.size(); i++) stream >> v[i];
  return stream;
}
template <class T1, class T2>
istream& operator>>(istream& stream, pair<T1, T2>& p) {
  return stream >> p.first >> p.second;
}
template <class T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
  for (long long i = 0; i < (long long)v.size(); i++) stream << v[i] << ' ';
  stream << '\n';
  return stream;
}
template <class T1, class T2>
ostream& operator<<(ostream& stream, const pair<T1, T2>& p) {
  return stream << p.first << ' ' << p.second;
}
const long long N = 5e5;
vector<vector<long long>> gr;
vector<bool> used;
vector<long long> way;
vector<pair<long long, long long>> ans;
vector<long long> h;
long long n;
void dfs(long long v, long long curh = 0) {
  used[v] = true;
  if (h[curh] != -1) {
    ans.push_back({v, h[curh]});
    h[curh] = -1;
  } else
    h[curh] = v;
  way.push_back(v);
  if (2 * way.size() >= n) return;
  for (long long u : gr[v])
    if (!used[u] && 2 * way.size() < n) dfs(u, curh + 1);
  if (2 * way.size() < n) way.pop_back();
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long m;
    cin >> n >> m;
    gr.assign(n, vector<long long>());
    way.clear();
    ans.clear();
    used.assign(n, false);
    h.assign(n, -1);
    for (long long i = 0; i < m; i++) {
      long long a, b;
      cin >> a >> b;
      a--, b--;
      gr[a].push_back(b);
      gr[b].push_back(a);
    }
    dfs(0);
    if (way.size()) {
      cout << "PATH\n" << way.size() << '\n';
      for (long long x : way) cout << x + 1 << ' ';
      cout << '\n';
    } else {
      cout << "PAIRING\n" << ans.size() << '\n';
      for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
    }
  }
}
