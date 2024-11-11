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
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pss = pair<string, string>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (ll i = 0; i < (ll)(n); ++i) cin >> v[i];
  string str;
  cin >> str;
  char prev = str[0];
  ll ans = 0;
  set<int, greater<int>> s;
  for (ll i = 0; i < (ll)(n); ++i) {
    if (str[i] == prev)
      s.insert(v[i]);
    else {
      int cont = 1;
      for (auto j = s.begin(); j != s.end() && cont <= k; ++cont, ++j)
        ans += *j;
      s.clear();
      prev = str[i];
      s.insert(v[i]);
    }
  }
  int cont = 1;
  for (auto j = s.begin(); j != s.end() && cont <= k; ++cont, ++j) ans += *j;
  cout << ans;
}
int main() {
  solve();
  return 0;
}
