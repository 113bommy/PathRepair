#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], long long n) {
  for (long long i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
void solve() {
  long long x;
  cin >> x;
  vector<long long> store;
  long long n = 1;
  long long push = 0;
  long long ans = 0;
  while (1) {
    push += n;
    ans++;
    long long cm = (((push) * (push)) + push) / 2;
    if (cm >= x) {
      if (cm > x)
        cout << ans - 1 << '\n';
      else
        cout << ans << '\n';
      return;
    }
    x -= cm;
    n *= 2;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  ;
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
