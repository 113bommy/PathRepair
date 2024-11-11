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
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const long long N = 0;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    long long cnt = 0;
    for (long long j = i; j < n; j++) {
      cnt += (s[j] == 'a' ? 1 : -1);
      if (cnt == 0) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << "-1 -1\n";
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
