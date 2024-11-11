#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int MAX_N = 1e6 + 5;
const long long mod = 1e9 + 7;
int n, t, a, b;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (1), _end_ = (n + 1); i < _end_; ++i) {
    cin >> t;
    if (t == 1) {
      a++;
    } else if (t == 2) {
      b++;
    }
  }
  int ans = 0;
  if (b <= a)
    ans = b + a / 3;
  else {
    ans = a;
  }
  cout << ans << '\n';
  return 0;
}
