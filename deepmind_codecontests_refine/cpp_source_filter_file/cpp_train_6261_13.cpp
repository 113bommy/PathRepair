#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "   ";
  err(++it, args...);
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char ch) { return string("'") + ch + string("'"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class InputIterator>
string to_string(InputIterator first, InputIterator last) {
  bool start = true;
  string res = "{";
  while (first != last) {
    if (!start) {
      res += ", ";
    }
    start = false;
    res += to_string(*first);
    ++first;
  }
  res += "}";
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
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename A, typename B>
istream& operator>>(istream& input, pair<A, B>& x) {
  input >> x.first >> x.second;
  return input;
}
template <typename A>
istream& operator>>(istream& input, vector<A>& x) {
  for (auto& i : x) input >> i;
  return input;
}
vector<long long> prefix_function(string s) {
  long long n = (long long)s.length();
  vector<long long> pi(n);
  for (long long i = 1; i < n; i++) {
    long long j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a[2], b[2];
  a[0] = a[1] = b[0] = b[1] = 0;
  string s, t;
  cin >> s >> t;
  for (char i : s) a[i - '0']++;
  for (char i : t) b[i - '0']++;
  vector<long long> p = prefix_function(t);
  if (a[0] < b[0] || a[1] < b[1]) {
    cout << s << '\n';
    return 0;
  }
  cout << t;
  a[0] -= b[0], a[1] -= b[1];
  long long h = p[(long long)t.size() - 1];
  string y = t.substr(0);
  long long c[2];
  c[1] = c[0] = 0;
  for (__typeof((long long)t.size()) i = (h) - ((h) > ((long long)t.size()));
       i != ((long long)t.size()) - ((h) > ((long long)t.size()));
       i += 1 - 2 * ((h) > ((long long)t.size())))
    c[t[i] - '0']++;
  long long g[2];
  g[0] = g[1] = 0;
  if (c[0] != 0)
    g[0] = a[0] / c[0];
  else
    g[0] = (long long)1e6 + 1;
  if (c[1] != 0)
    g[1] = a[1] / c[1];
  else
    g[1] = (long long)1e6 + 1;
  long long r = min(g[0], g[1]);
  for (__typeof(r) i = (0) - ((0) > (r)); i != (r) - ((0) > (r));
       i += 1 - 2 * ((0) > (r)))
    cout << y;
  a[0] -= r * c[0], a[1] -= r * c[1];
  for (__typeof(a[0]) i = (0) - ((0) > (a[0])); i != (a[0]) - ((0) > (a[0]));
       i += 1 - 2 * ((0) > (a[0])))
    cout << 0;
  for (__typeof(a[1]) i = (0) - ((0) > (a[1])); i != (a[1]) - ((0) > (a[1]));
       i += 1 - 2 * ((0) > (a[1])))
    cout << 1;
}
