#include <bits/stdc++.h>
using namespace std;
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  return os << "(" << v.first << ", " << v.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = int(0); i <= int((static_cast<int>((v).size())) - 1); ++i) {
    if (i) os << ", ";
    os << v[i];
  }
  return os << "]";
}
template <class T>
bool setmax(T& _a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T& _a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = int(0); i <= int((n)-1); ++i) cin >> a[i];
  int ans = 0;
  for (int i = int(0); i <= int((m)-1); ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    int s = 0;
    for (int j = int(l); j <= int((r)-1); ++j) s += a[j];
    if (s > 0) ans += s;
  }
  cout << ans << endl;
  return 0;
}
