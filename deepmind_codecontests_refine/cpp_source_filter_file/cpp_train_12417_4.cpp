#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  cerr << "here\n";
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
clock_t start;
double runtime() { return (double)(clock() - start) / CLOCKS_PER_SEC; }
const ll MOD = 1e9 + 7;
ll inv(ll a) { return pow(a, MOD - 2); }
ll pow(ll a, ll p) {
  ll prod = 1;
  while (p > 0) {
    if (p & 1) prod = prod * a % MOD;
    a = a * a % MOD;
    p >>= 1;
  }
  return prod;
}
void solve() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int n = s.size();
  ll ans = 0, sum = 0;
  ll p = 1;
  for (int i = 0; i < n; ++i) {
    ll tmp = (ll)(s[i] - '0') * p % MOD;
    ans = (ans + (tmp * ((n - i - 1) * (n - i) / 2) % MOD)) % MOD;
    42;
    ans = (ans + ((ll)(s[i] - '0') * sum) % MOD) % MOD;
    sum = (sum + p * (i + 1) % MOD) % MOD;
    p = p * 10 % MOD;
  }
  cout << ans << '\n';
}
int main() {
  start = clock();
  ios ::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
