#include <bits/stdc++.h>
using namespace std;
inline void read() {}
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
long long arr[150007];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  for (__typeof(n + 1) i = 1; i < (n + 1); i++) cin >> arr[i];
  for (__typeof(n + 1) i = 1; i < (n + 1); i++) {
    arr[i] += arr[i - 1];
  }
  long long a, b, res = 0;
  while (m--) {
    cin >> a >> b;
    if (arr[b] - arr[a - 1] > 0) {
      res += arr[b] - arr[a - 1];
    }
  }
  cout << res << "\n";
  return 0;
}
