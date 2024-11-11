#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
template <class T, class U>
inline void checkmin(T &x, U y) {
  if (y < x) x = y;
}
template <class T, class U>
inline void checkmax(T &x, U y) {
  if (y > x) x = y;
}
template <class T, class U>
inline bool ifmax(T &x, U y) {
  if (y > x) return x = y, true;
  return false;
}
template <class T, class U>
inline bool ifmin(T &x, U y) {
  if (y < x) return x = y, true;
  return false;
}
template <class T>
inline void sort(T &a) {
  sort(a.begin(), a.end());
}
template <class T>
inline void rsort(T &a) {
  sort(a.rbegin(), a.rend());
}
template <class T>
inline void reverse(T &a) {
  reverse(a.begin(), a.end());
}
template <class T, class U>
inline istream &operator>>(istream &str, pair<T, U> &p) {
  return str >> p.first >> p.second;
}
template <class T>
inline istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) str >> i;
  return str;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  sort(a);
  a.resize(unique(a.begin(), a.end()) - a.begin());
  reverse(a);
  int ans = a[0];
  for (int i = 0; i < signed(a.size()); ++i)
    if (i == 0 || a[i] * 2 == a[0]) {
      for (int j = i + 1; j < signed(a.size()); ++j) {
        if (a[i] % a[j] == 0) continue;
        checkmax(ans, a[i] + a[j]);
        for (int k = j + 1; k < signed(a.size()); ++k) {
          if (a[i] % a[k] == 0 || a[j] % a[k] == 0) continue;
          checkmax(ans, a[i] + a[j] + a[k]);
          break;
        }
      }
    }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  srand(94385);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
