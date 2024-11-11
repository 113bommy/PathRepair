#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 2e5 + 5;
vector<int> f[N];
void sieve() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      f[j].push_back(i);
    }
  }
}
using ll = long long;
void solve() {
  int n, m;
  ll l, r;
  cin >> n >> m >> l >> r;
  set<pair<int, int> > s;
  int u = m;
  int v = m;
  for (int x1 = 1; x1 < n + 1; x1++) {
    while (1LL * x1 * u >= l) {
      for (int fac : f[u]) {
        s.insert({fac, u});
      }
      u--;
    }
    while (1LL * x1 * v > r) {
      for (int fac : f[v]) {
        s.erase({fac, v});
      }
      v--;
    }
    bool found = 0;
    for (int z : f[x1]) {
      auto it = s.upper_bound({z, m + 10});
      if (it == s.end()) {
        break;
      }
      int x2 = 1LL * x1 * (it->first) / z;
      assert(z > 0);
      if (x2 <= n) {
        int y1 = it->second;
        int y2 = 1LL * y1 * z / (it->first);
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
        found = 1;
        break;
      }
    }
    if (!found) {
      cout << "-1\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sieve();
  int t = 1;
  while (t--) solve();
  return 0;
}
