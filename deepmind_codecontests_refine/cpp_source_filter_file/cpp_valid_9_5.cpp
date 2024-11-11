#include <bits/stdc++.h>
using namespace std;
template <typename T>
T min_(T a, T b) {
  return a > b ? b : a;
}
template <typename T, typename... Ts>
T min_(T first, Ts... last) {
  return min_(first, min_(last...));
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
template <class T, class S>
std::ostream& operator<<(std::ostream& os, const std::pair<T, S>& t) {
  os << "(" << t.first << ", " << t.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last) out << ", ";
  }
  out << "]";
  return out;
}
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int cnt[27];
  memset(cnt, 0, sizeof cnt);
  int red = 0;
  for (auto i = 0; i < n; i++) {
    if (cnt[s[i] - 'a'] > 2) continue;
    cnt[s[i] - 'a']++;
    red++;
  }
  cout << red / 2 << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
