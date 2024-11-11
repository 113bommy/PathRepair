#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
void ndarray(vector<T> &vec, const V &val, int len) {
  vec.assign(len, val);
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (auto v : vec) os << v << ' ';
  return os;
}
const int MOD = (int)1e9 + 7;
const int MAX = (int)1e9 + 7;
const long long MAXLL = (long long)1e18 + 7;
int t;
void solve() {
  long long a, b, n;
  cin >> a >> b >> n;
  long long gap = (abs(a) + abs(b) - n);
  if (gap >= 0 && !(gap & 1)) {
    cout << "YES" << '\n';
  } else
    cout << "NO" << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (0) {
    cin >> t;
    while (t--) solve();
  } else {
    solve();
  }
}
