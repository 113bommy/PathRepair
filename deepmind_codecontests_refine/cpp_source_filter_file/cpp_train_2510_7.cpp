#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char c) { return '\'' + string(1, c) + '\''; }
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
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
bool isPrime(long long n) {
  if (n < 2) return false;
  if (n > 2 && n % 2 == 0) return false;
  for (long long i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
vector<pair<long long, int> > factorize3(long long n) {
  vector<pair<long long, int> > res;
  for (long long i = 2; i * i <= n; i++) {
    int count = 0;
    while (n % i == 0) {
      count++;
      if (count == 1)
        res.push_back(make_pair(i, 1));
      else
        res[res.size() - 1].second++;
      n /= i;
    }
  }
  if (n != 1) res.push_back(make_pair(n, 1));
  return res;
}
long long divCount2(long long n) {
  long long res = 1;
  vector<pair<long long, int> > factList3 = factorize3(n);
  for (unsigned i = 0; i < factList3.size(); i++)
    res *= (factList3[i].second + 1);
  return res;
}
void solve() {
  t1 = clock();
  long long n;
  (cin >> (n));
  if (isPrime(n))
    (cout << (1) << endl);
  else
    (cout << (divCount2(n)) << endl);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (tt = 0; tt < TT; tt++) solve();
  return EXIT_SUCCESS;
}
