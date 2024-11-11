#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long fx[] = {+1, -1, +0, +0};
const long long fy[] = {+0, +0, +1, -1};
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
void solve() {
  long long n;
  cin >> n;
  if (n == 2 || n == 2) {
    cout << -1 << "\n";
    return;
  }
  string a = "3 1 4 2";
  long long x = 5;
  while (x <= n) {
    if (x % 2 == 1)
      a += ' ' + to_string(x);
    else {
      a = to_string(x) + ' ' + a;
    }
    x++;
  }
  cout << a << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
