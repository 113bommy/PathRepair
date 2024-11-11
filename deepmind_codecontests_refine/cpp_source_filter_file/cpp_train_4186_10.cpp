#include <bits/stdc++.h>
using namespace std;
__attribute__((constructor)) static void fast_cin() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
using ll = int64_t;
using ull = uint64_t;
using mp = pair<uint16_t, uint16_t>;
using mt = tuple<uint8_t, uint8_t, uint8_t>;
template <typename T, typename R>
istream &operator>>(istream &fin, pair<T, R> &p) {
  fin >> p.first >> p.second;
  return fin;
}
template <typename T, typename R>
ostream &operator<<(ostream &fout, const pair<T, R> &p) {
  fout << "{" << p.first << ", " << p.second << "} ";
  return fout;
}
template <typename T>
ostream &operator<<(ostream &fout, const vector<T> &vec) {
  for (size_t i = 0; i < vec.size(); i++) fout << vec[i] << ' ';
  return fout;
}
template <typename T>
istream &operator>>(istream &fin, vector<T> &vec) {
  for (size_t i = 0; i < vec.size(); i++) fin >> vec[i];
  return fin;
}
vector<string> split(const string &s, char c) {
  vector<string> v;
  ull st = 0, fn = 0, lvl = 0;
  for (; fn < s.size(); fn++) {
    if (s[fn] == c && lvl == 0) {
      v.push_back(s.substr(st, fn - st));
      st = fn + 1;
    }
    if (s[fn] == '(') {
      lvl++;
    }
    if (s[fn] == ')') {
      lvl--;
    }
  }
  v.push_back(s.substr(st, fn - st));
  return v;
}
void pr_var(vector<string>::iterator it) {
  (void)it;
  cerr << endl;
}
template <typename T, typename... Args>
void pr_var(vector<string>::iterator it, T a, Args... args) {
  cerr << *it << "=" << a << "  ";
  pr_var(++it, args...);
}
ll div_ceil(ll n, ll d) {
  ll res = n / d;
  if (res >= 0) res += n % d ? 1 : 0;
  return res;
}
ll gcd(ll a, ll b) {
  a = llabs(a);
  b = llabs(b);
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}
ll lcm(ll a, ll b) {
  ll c = gcd(a, b);
  return c == 0 ? 0 : llabs(a / c * b);
}
const double PI = acos(-1.0);
constexpr double EPS = 1e-9;
constexpr ll INF = numeric_limits<ll>::max();
constexpr ll MOD = 1e9 + 7;
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll res = n;
    for (ll i = 0; i < n; i++) {
      if (s[i] != '1') continue;
      res = max(max(i, n - i) * 2, res);
    }
    cout << res << endl;
  }
  return 0;
}
