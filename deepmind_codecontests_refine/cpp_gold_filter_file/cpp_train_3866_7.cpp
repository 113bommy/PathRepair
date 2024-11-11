#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
const long long INF = 1LL << 60;
const double PI = acos(-1);
using ll = long long;
using P = array<ll, 2>;
template <typename T>
istream& operator>>(istream& i, vector<T>& v) {
  for (ll j = (0); j < (ll)(v.size()); ++j) i >> v[j];
  return i;
}
template <typename T>
string join(vector<T>& v) {
  stringstream s;
  for (ll i = (0); i < (ll)(v.size()); ++i) s << ' ' << v[i];
  return s.str().substr(1);
}
template <typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
  if (v.size()) o << join(v);
  return o;
}
template <typename T>
string join(vector<vector<T>>& vv) {
  string s = "\n";
  for (ll i = (0); i < (ll)(vv.size()); ++i) s += join(vv[i]) + "\n";
  return s;
}
template <typename T>
ostream& operator<<(ostream& o, vector<vector<T>>& vv) {
  if (vv.size()) o << join(vv);
  return o;
}
template <typename T1, typename T2>
istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, pair<T1, T2>& v) {
  return o << v.first << "," << v.second;
}
template <typename T>
istream& operator>>(istream& i, array<T, 2>& v) {
  return i >> v[0] >> v[1];
}
template <typename T>
ostream& operator<<(ostream& o, array<T, 2>& v) {
  return o << v[0] << " " << v[1];
}
void init_init_init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout << fixed << setprecision(10);
}
template <class T>
T up(T a, T b) {
  assert(b);
  return (a + b - 1) / b;
}
template <typename... A>
bool eq(A const&... a) {
  auto t = {a...};
  assert(t.size());
  auto tar = *t.begin();
  for (const auto& e : t)
    if (tar != e) return false;
  return true;
}
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
template <class T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmax(T& a, initializer_list<T> l) {
  return chmax(a, max(l));
}
template <class T>
bool chmin(T& a, initializer_list<T> l) {
  return chmin(a, min(l));
}
int main(int argc, char** argv) {
  init_init_init();
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll su{0};
  for (ll i = (0); i < (ll)(N); ++i) su += (S[i] == '(') ? 1 : -1;
  if (su == 2) {
    reverse((S).begin(), (S).end());
    for (ll i = (0); i < (ll)(N); ++i) S[i] = (S[i] == ')') ? '(' : ')';
  } else if (su == -2) {
  } else {
    std::cout << 0 << std::endl;
    return 0;
  }
  ll res{0};
  ll cn{0};
  ll mi{0};
  for (ll i = (0); i < (ll)(N); ++i) {
    cn += (S[i] == '(') ? 1 : -1;
    if (S[i] == ')')
      if (mi >= 0) ++res;
    chmin(mi, cn);
    if (mi < -2) {
      std::cout << 0 << std::endl;
      return 0;
    }
  }
  std::cout << res << std::endl;
}
