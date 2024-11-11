#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]\n";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << ", " << P.second << ")\n";
}
template <class T>
ostream& operator<<(ostream& os, set<T> second) {
  os << "{ ";
  for (auto s : second) os << s << " ";
  return os << "}\n";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}\n";
}
void solve() {
  long long n, a[3], b[3], maxm, minm = 0;
  cin >> n;
  for (__typeof(3) i = 0; i < 3; ++i) cin >> a[i];
  for (__typeof(3) i = 0; i < 3; ++i) cin >> b[i];
  maxm = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
  for (__typeof(3) i = 0; i < 3; ++i) {
    long long x = a[i] - b[i] + b[(i + 2) % 3];
    if (x >= 0) {
      minm = x;
      break;
    }
  }
  cout << minm << " " << maxm;
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  if (!t) cin >> t;
  while (t--) solve();
}
