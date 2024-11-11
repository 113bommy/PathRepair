#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T, typename TT>
inline ostream &operator<<(ostream &os, const pair<T, TT> &t) {
  return os << t.first << " " << t.second;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &t) {
  for (auto i : t) os << i << " ";
  return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &t) {
  for (auto i : t) os << i << " ";
  return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
  for (auto i : t) os << i.first << " : " << i.second << '\n';
  return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
  for (T &t : v) is >> t;
  return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
  for (pair<T1, T2> &t : v) is >> t.first >> t.second;
  return is;
}
const long long mod = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  cin >> v;
  map<long long, long long> m;
  m[0] = 1;
  vector<long long> pw = {1};
  if (k == -1)
    pw.push_back(-1);
  else if (abs(k) != 1)
    while (pw.back() * k < 1e15) pw.push_back(pw.back() * k);
  long long pre = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    pre += v[i];
    for (int j = 0; j < pw.size(); j++) {
      if (m.find(pre - pw[j]) != m.end()) ans += m[pre - pw[j]];
    }
    m[pre]++;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
