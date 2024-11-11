#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
inline ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <class T, class U>
inline istream& operator>>(istream& os, pair<T, U>& p) {
  os >> p.first >> p.second;
  return os;
}
template <class T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  if (v.empty()) return os;
  if (v.begin() != v.end()) os << v.front();
  for (auto it = ++v.begin(); it != v.end(); ++it) os << ' ' << *it;
  return os;
}
template <class T>
inline istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
void Solve(istream& is, ostream& os) {
  int n;
  is >> n;
  int res = n / 2 + 1;
  os << res << '\n';
  for (int i = 1; i < res + 1; ++i) {
    os << i << ' ' << 1 << '\n';
  }
  for (int i = 2; i < n - res + 2; ++i) {
    os << res << ' ' << i << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(15) << fixed;
  Solve(cin, cout);
  return 0;
}
