#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int ah = 911382323;
int bh = 972663749;
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  typename vector<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  typename set<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v) {
  os << "[";
  typename map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
long long dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
long long n, a[20];
bool sorted(long long low, long long high) {
  if (low == high) return 1;
  long long f = 1;
  if (high - low == 1) {
    return a[low] <= a[high];
  }
  for (long long i = low; i < high - 1; i++) {
    if (a[i] > a[i + 1]) f = 0;
  }
  return f;
}
long long fun(long long low, long long high) {
  if (sorted(low, high)) return high - low + 1;
  long long mid = (low + high) / 2;
  return max(fun(low, mid), fun(mid + 1, high));
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  cout << fun(0, n - 1);
}
