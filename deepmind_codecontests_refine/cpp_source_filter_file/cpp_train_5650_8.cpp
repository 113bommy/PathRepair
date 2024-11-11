#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  long long sum = 0, mx = 0;
  for (auto &i : arr) cin >> i, sum += i, uax(mx, i);
  if (mx * 2 > (sum) || (n & 1))
    cout << "T" << '\n';
  else
    cout << "HL" << '\n';
}
signed main() {
  cin.tie(NULL), ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
