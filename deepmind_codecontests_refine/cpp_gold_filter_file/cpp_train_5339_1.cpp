#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &i : vec) {
    is >> i;
  }
  return is;
}
template <typename E>
ostream &operator<<(ostream &os, pair<E, E> &t) {
  os << t.first << ' ' << t.second;
  return os;
}
template <typename E>
ostream &operator<<(ostream &os, pair<const E, E> &t) {
  os << t.first << ' ' << t.second;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  for (T i : vec) {
    os << i << ' ';
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T> > &vec) {
  for (vector<T> i : vec) {
    os << i << '\n';
  }
  return os;
}
int32_t main() {
  cin.tie(NULL);
  cout.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(10);
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    cin >> a;
    vector<long long> b;
    long long i = 1;
    while (i < n) {
      long long sz = 1;
      while (i < n - 1 && a[i + 1] > a[i]) {
        sz += 1;
        i += 1;
      }
      b.push_back(sz);
      i += 1;
    }
    long long ans = 0;
    long long sz = b[0];
    long long cur_sz = 0;
    i = 1;
    while (i < b.size()) {
      for (long long j = 0; j < sz; ++j) {
        cur_sz += b[i + j];
      }
      i += sz;
      sz = cur_sz;
      cur_sz = 0;
      ans += 1;
    }
    cout << ans + 1 << '\n';
  }
  return 0;
}
