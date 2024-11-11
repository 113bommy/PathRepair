#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
string to_str(const int &n) {
  ostringstream stm;
  stm << n;
  return stm.str();
}
string to_str(const long long &n) {
  ostringstream stm;
  stm << n;
  return stm.str();
}
template <class T>
string tostring(T x, int len = 0) {
  stringstream ss;
  ss << x;
  string r = ss.str();
  if (int((r).size()) < len) r = string(len - int((r).size()), '0') + r;
  return r;
}
template <class T>
void convert(string x, T &r) {
  stringstream ss(x);
  ss >> r;
}
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
long long modinv(long long a) { return powmod(a, 1000000007 - 2); }
long long modinv(long long a, long long m) { return powmod(a, m - 2); }
long long nCkMp(long long n, long long k) {
  long long numerator = 1, denominator = 1;
  for (int i = 0; i < k; i++) numerator = (numerator * (n - i)) % 1000000007;
  for (int i = 1; i <= k; i++) denominator = (denominator * i) % 1000000007;
  return (numerator * modinv(denominator)) % 1000000007;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int TT = 1, tt;
clock_t t1;
void solve() {
  t1 = clock();
  int n, c, q;
  (cin >> (n));
  vector<bool> x(n + 1);
  c = n;
  for (auto i = (0); i < (n); i++) {
    (cin >> (q));
    x[q] = true;
    if (q == c) {
      while (x[q]) {
        cout << q << " ";
        q--;
        c--;
      };
    } else
      (cout << ("") << endl);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (tt = 0; tt < TT; tt++) solve();
  return 0;
}
