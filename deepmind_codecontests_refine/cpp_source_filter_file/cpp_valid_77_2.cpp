#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using vt = vector<T>;
template <class T>
using vvt = vt<vt<T>>;
template <class T, class U>
using pr = pair<T, U>;
template <class T, class U>
using vpr = vt<pr<T, U>>;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
  static uint64_t split_mix_64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t r =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return split_mix_64(x + r);
  }
};
template <class T>
bool mxx(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template <class T>
bool mnn(T& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <class T>
T f_div(const T& a, const T& b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
template <class T>
T c_div(const T& a, const T& b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
template <class T>
ostream& operator<<(ostream& out, const vt<T>& v) {
  for (auto& c : v) out << c << ' ';
  return out << '\n';
}
ostream& operator<<(ostream& out, const vvt<char>& v) {
  for (auto& r : v) {
    for (auto& c : r) out << c;
    out << '\n';
  }
  return out << "";
}
template <class T>
ostream& operator<<(ostream& out, const vvt<T>& v) {
  for (auto& r : v) out << r;
  return out << "";
}
template <class T, class U>
ostream& operator<<(ostream& out, const pr<T, U>& p) {
  return out << p.first << ' ' << p.second;
}
template <class T, class U>
ostream& operator<<(ostream& out, const vpr<T, U>& v) {
  for (auto& p : v) out << p;
  return out << "";
}
template <class T>
istream& operator>>(istream& in, vt<T>& v) {
  for (int i = 0; i < (int)(v).size() - 1; ++i) in >> v[i];
  return in >> v.back();
}
template <class T, class U>
istream& operator>>(istream& in, pr<T, U>& p) {
  return in >> p.first >> p.second;
}
template <class T, class U>
istream& operator>>(istream& in, vpr<T, U>& v) {
  for (int i = 0; i < (int)(v).size() - 1; ++i) in >> v[i];
  return in >> v.back();
}
const int MOD0 = 1e9 + 7, MOD1 = 998244353;
const int MAX0 = 2e5 + 5, MAX1 = 1e7 + 5;
const ll MAX2 = (ll)1e18 + 5;
const int DI[] = {-1, +1, 0, 0, -1, +1, -1, +1};
const int DJ[] = {0, 0, +1, -1, +1, -1, -1, +1};
void dbg(const string& s = "../test", bool usaco = false) {
  freopen((s + ".in" + (usaco ? "" : ".txt")).c_str(), "r", stdin);
  freopen((s + ".out" + (usaco ? "" : ".txt")).c_str(), "w", stdout);
}
void solve(int test) {
  ll n, m;
  cin >> n >> m;
  vt<ll> dp(n + 1, 0);
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] += (2 * dp[i - 1] + (i > 2)) % m;
    for (int j = 2 * i; j <= n; j += i) (dp[j] += dp[i] - dp[i - 1] + m) %= m;
  }
  cout << dp[n] << '\n';
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int cases = 1;
  for (int test = 1; test <= cases; ++test) solve(test);
}
