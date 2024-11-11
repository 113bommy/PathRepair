#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& p) {
  return o << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& vc) {
  o << "{";
  for (const T& v : vc) o << v << ",";
  o << "}";
  return o;
}
long long n, k, sum[303030], p[303030], x[303030], y[303030], w[303030];
vector<long long> adj[303030];
void dfs(long long s) {
  sum[s] = 1;
  for (auto t : adj[s]) {
    if (p[s] != t) {
      p[t] = s;
      dfs(t);
      sum[s] += sum[t];
    }
  }
}
void solve() {
  cin >> k;
  n = 2 * k;
  for (long long i = 1; i <= n; i++) {
    sum[i] = 0;
    adj[i].clear();
    p[i] = -1;
  }
  for (long long i = 1; i < n; i++) {
    cin >> x[i] >> y[i] >> w[i];
    adj[x[i]].push_back(y[i]);
    adj[y[i]].push_back(x[i]);
  }
  dfs(1);
  long long ansl = 0, ansr = 0;
  for (long long i = 1; i < n; i++) {
    if (x[i] == p[y[i]]) {
      long long l = sum[y[i]];
      long long r = n - l;
      ansr += min(l, r) * w[i];
      ansl += (l % 2) * w[i];
    } else {
      long long l = sum[x[i]];
      long long r = n - l;
      ansr += min(l, r) * w[i];
      ansl += (l % 2) * w[i];
    }
  }
  cout << ansl << " " << ansr << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(8);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
