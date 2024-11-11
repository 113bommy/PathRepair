#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long inf = numeric_limits<long long>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
inline void solve(), read();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
  return 0;
}
struct comp {
  long long n = 1;
  vector<long long> worst, best;
  comp() {}
  comp(vector<long long>& w, vector<long long>& b) { worst = w, best = b; }
  bool operator<(const comp& c) const {
    for (long long i = 0; i < (long long)((best).size()); i++) {
      if (best[i] >= c.worst[i]) {
        return 0;
      }
    }
    return 1;
  }
  void merge(const comp& c) {
    n += c.n;
    for (long long i = 0; i < (long long)((best).size()); i++) {
      (best[i]) = ((best[i]) < (c.best[i])) ? (c.best[i]) : (best[i]);
      (worst[i]) = ((worst[i]) > (c.worst[i])) ? (c.worst[i]) : (worst[i]);
    }
  }
};
long long n, k;
vector<vector<long long> > s;
set<comp> q;
inline void solve() {
  for (long long i = 0; i < n; i++) {
    comp c(s[i], s[i]);
    auto it0 = q.lower_bound(c), it1 = q.upper_bound(c);
    while (it0 != it1) {
      c.merge(*it0);
      it0 = q.erase(it0);
    }
    q.insert(c);
    auto it = q.rbegin();
    cout << it->n << "\n";
  }
}
inline void read() {
  cin >> n >> k;
  s.resize(n, vector<long long>(k, 0));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < k; j++) {
      cin >> s[i][j];
    }
  }
}
