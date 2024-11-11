#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _dbg(char const* s, const T& t) {
  cout << s << "=" << t << endl;
}
template <typename T, typename... TA>
void _dbg(char const* s, const T& t, const TA&... ta) {
  while (*s != ',') cout << *s++;
  cout << "=" << t << ",";
  _dbg(s + 1, ta...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ",";
    os << *it;
  }
  return os << "}";
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& mp) {
  os << "{";
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    if (it != mp.begin()) os << ",";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (it != s.begin()) os << ",";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
  os << "{";
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (it != s.begin()) os << ",";
    os << *it;
  }
  return os << "}";
}
template <size_t N>
ostream& operator<<(ostream& os, const bitset<N>& bs) {
  os << "{";
  for (size_t i = 0; i < N; ++i) {
    cout << bs[i];
  }
  return os << "}";
}
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using namespace std;
void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> m;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    int cur;
    cin >> cur;
    v[i] = cur;
    ++m[cur];
  }
  unordered_set<int> s;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (--m[v[i]] == 0) m.erase(v[i]);
    if (s.find(v[i]) == s.end()) {
      ans += m.size();
      s.insert(v[i]);
    }
  }
  cout << ans;
}
int main() {
  solve();
  return 0;
}
