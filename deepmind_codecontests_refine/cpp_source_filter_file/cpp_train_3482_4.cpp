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
const int MOD = 1000000007;
int n;
ll s, f[22];
ll inv(ll a, ll b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }
ll add(ll x, ll y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
ll mul(ll x, ll y) { return (x * y) % MOD; }
ll comb(ll n, ll k) {
  if (k > n) return 0;
  ll ret = 1;
  for (int i = 0; i < k; ++i) {
    ret = mul(ret, n - i);
    ret = mul(ret, inv(k - i, MOD));
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }
  ll sub = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    int Sz = 0;
    ll x = n - 1 + s;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        x -= f[i] + 1;
        ++Sz;
      }
    }
    ll v = comb(x, n - 1);
    if (Sz & 1)
      sub = add(sub, v);
    else
      sub = add(sub, -v);
  }
  ll ans = add(comb(n - 1 + s, n - 1), -sub);
  cout << ans << '\n';
  return 0;
}
