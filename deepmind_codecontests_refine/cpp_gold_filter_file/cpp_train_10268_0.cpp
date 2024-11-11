#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char ch) {
  string s;
  s += ch;
  return s;
}
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
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
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
vector<long long> fac(maxn), invfac(maxn);
long long expmod(long long x, long long n, long long mod) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    long long temp = expmod(x, n / 2, mod);
    return (temp * temp) % mod;
  } else {
    return (expmod(x, n - 1, mod) * x) % mod;
  }
}
long long modinv(long long x, long long mod) { return expmod(x, mod - 2, mod); }
void find_fac() {
  fac[0] = 1;
  invfac[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = invfac[i - 1] * modinv(i, mod) % mod;
  }
}
long long C(int n, int k) {
  if (k > n)
    return 0;
  else {
    return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> s(n), g(n);
  for (int i = (int)0; i < (int)n; i++) cin >> s[i] >> g[i];
  vector<int> L(n), R(n);
  L[0] = s[0] + g[0];
  for (int i = (int)1; i < (int)n; i++) L[i] = min(L[i - 1] + 1, s[i] + g[i]);
  R[n - 1] = s[n - 1] + g[n - 1];
  for (int i = (int)n - 2; i >= (int)0; i--)
    R[i] = min(R[i + 1] + 1, s[i] + g[i]);
  vector<int> ans(n);
  long long road = 0;
  for (int i = (int)0; i < (int)n; i++) {
    ans[i] = min(L[i], R[i]);
    road += ans[i] - s[i];
    if (ans[i] < s[i] || ans[i] > s[i] + g[i]) {
      cout << "-1\n";
      return;
    }
  }
  cout << road << "\n";
  for (int i = (int)0; i < (int)n; i++) cout << ans[i] << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
}
