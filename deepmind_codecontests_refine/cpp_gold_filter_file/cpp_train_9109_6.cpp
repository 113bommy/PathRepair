#include <bits/stdc++.h>
using namespace std;
template <int POS, class TUPLE>
void deploy(std::ostream &os, const TUPLE &tuple) {}
template <int POS, class TUPLE, class H, class... Ts>
void deploy(std::ostream &os, const TUPLE &t) {
  os << (POS == 0 ? "" : ", ") << get<POS>(t);
  deploy<POS + 1, TUPLE, Ts...>(os, t);
}
template <class T, class U>
std::ostream &operator<<(std::ostream &os, std::pair<T, U> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &v) {
  int remain = v.size();
  os << "{";
  for (auto e : v) os << e << (--remain == 0 ? "}" : ", ");
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::set<T> &v) {
  int remain = v.size();
  os << "{";
  for (auto e : v) os << e << (--remain == 0 ? "}" : ", ");
  return os;
}
template <class T, class K>
std::ostream &operator<<(std::ostream &os, std::map<T, K> &make_pair) {
  int remain = make_pair.size();
  os << "{";
  for (auto e : make_pair)
    os << "(" << e.first << " -> " << e.second << ")"
       << (--remain == 0 ? "}" : ", ");
  return os;
}
using ll = long long;
ll xs[2010], ys[2010];
ll P[2][2];
int N;
vector<int> cnt[2010];
ll calc(ll x, ll y, ll x2, ll y2) {
  return (x - x2) * (x - x2) + (y - y2) * (y - y2);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < (2); i++) {
    for (int j = 0; j < (2); j++) {
      cin >> P[i][j];
    }
  }
  ll r1 = 0, r2 = 0;
  vector<pair<ll, int> > ds;
  for (int i = 0; i < (N); i++) {
    int x, y;
    cin >> x >> y;
    xs[i] = x;
    ys[i] = y;
    ds.push_back(make_pair(calc(x, y, P[0][0], P[0][1]), i));
  }
  sort((ds).begin(), (ds).end());
  reverse((ds).begin(), (ds).end());
  r1 = ds[0].first;
  ll foo = 0;
  for (int i = 0; i < (N); i++) {
    int j = ds[i].second;
    ll cr2 = calc(xs[j], ys[j], P[1][0], P[1][1]);
    foo = max(foo, cr2);
    ll nr1 = 0;
    if (i != N - 1) {
      nr1 = ds[i + 1].first;
    }
    if (nr1 + foo < r1 + r2) {
      r1 = nr1;
      r2 = foo;
    }
  }
  cout << r1 + r2 << "\n";
  return 0;
}
