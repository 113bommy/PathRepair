#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9;
const double EPS = 1e-9;
template <class T>
void _db(const char* dbStr, T e) {
  cout << dbStr << " = " << e << endl;
}
template <class T, class... L>
void _db(const char* dbStr, T e, L... r) {
  while (*dbStr != ',') cout << *dbStr++;
  cout << " = " << e << ',';
  _db(dbStr + 1, r...);
}
template <class S, class T>
ostream& operator<<(ostream& o, const map<S, T>& v) {
  o << "[";
  int i = 0;
  for (const pair<S, T>& pr : v)
    o << (!i++ ? "" : ", ") << "{" << pr.first << " : " << pr.second << "}";
  return o << "]";
}
template <template <class, class...> class S, class T, class... L>
ostream& operator<<(ostream& o, const S<T, L...>& v) {
  o << "[";
  int i = 0;
  for (const auto& e : v) o << (!i++ ? "" : ", ") << e;
  return o << "]";
}
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& pr) {
  return o << "(" << pr.first << ", " << pr.second << ")";
}
ostream& operator<<(ostream& o, const string& s) {
  for (const char& c : s) o << c;
  return o;
}
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
using VVV = VV<V<T>>;
using ll = long long;
using pii = pair<int, int>;
using vi = V<int>;
using vii = V<pii>;
using vvi = VV<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using si = set<int>;
using usi = unordered_set<int>;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin.tie(0);
  int a, b, x_1, y_1, x_2, y_2;
  cin >> a >> b >> x_1 >> y_1 >> x_2 >> y_2;
  ll ans = 0;
  {
    ll u = x_1 + y_1, v = x_2 + y_2;
    if (u > v) swap(u, v);
    while (u <= 0) u += 1000000000LL * a, v += 1000000000LL * a;
    true;
    ans = v / (2 * a) - u / (2 * a);
  }
  {
    ll u = -x_1 + y_1, v = -x_2 + y_2;
    if (u > v) swap(u, v);
    while (u <= 0) u += 1000000000LL * b, v += 1000000000LL * b;
    true;
    ans = max(ans, v / (2 * b) - u / (2 * b));
  }
  cout << ans << '\n';
  return 0;
}
