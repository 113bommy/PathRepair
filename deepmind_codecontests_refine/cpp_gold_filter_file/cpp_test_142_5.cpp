#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]\n"; }
template <typename T, typename... Args>
void DBG(T first, Args... args) {
  cerr << first;
  if (sizeof...(args)) cerr << ", ";
  DBG(args...);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long m, n;
  cin >> m >> n;
  vector<vector<long long>> v(m, vector<long long>(n));
  set<long long> s;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) cin >> v[i][j];
  }
  long long l = 0, r = 1e9 + 5;
  auto possible = [&](long long x) {
    vector<long long> columns(n);
    long long left = n;
    long long escape = -1;
    for (long long i = 0; i < m; i++) {
      long long two = 0;
      for (long long j = 0; j < n; j++) {
        if (v[i][j] >= x) two++;
      }
      if (two >= 2) {
        for (long long j = 0; j < n; j++) {
          if (v[i][j] >= x) columns[j] = 1;
        }
        left -= two;
        escape = i;
        break;
      }
    }
    if (left <= 0) {
      return true;
    }
    if (escape == -1) {
      return false;
    }
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        if (i == escape || columns[j] == 1) continue;
        if (v[i][j] >= x) left--, columns[j] = 1;
        if (left <= 0) {
          for (long long i = 0; i < n; i++) {
            if (columns[i] == 0) return false;
          }
          return true;
        }
      }
    }
    return false;
  };
  while (l <= r) {
    long long m = l + (r - l) / 2;
    if (possible(m)) {
      l = m + 1;
    } else
      r = m - 1;
  }
  cout << l - 1 << "\n";
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
