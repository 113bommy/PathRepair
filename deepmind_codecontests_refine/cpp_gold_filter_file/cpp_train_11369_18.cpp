#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
string to_string(char s) {
  string res = "'''";
  res[1] = s;
  return res;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug() { cout << "\n"; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug(T...);
}
const int M = 1e9 + 7;
inline int add(int a, int b, int p = M) {
  a = a + b;
  if (a >= p) a -= p;
  return a;
}
inline int sub(int a, int b, int p = M) {
  a = a - b;
  if (a < 0) a += p;
  return a;
}
inline int mul(int a, int b, int p = M) {
  a = (a * 1ll * b) % p;
  return a;
}
const ld pi = acos(-1), eps = 1e-9;
const ll inf = 1e18;
const int N = 1e4 + 5, K = 255;
void solve() {
  string s;
  cin >> s;
  ll h = 0;
  for (int i = 0; i <= s.length() - 1; i++) {
    if (s[i] == '>') {
      if (s[i - 2] == '/') h--;
      for (int j = 0; j <= (2 * h) - 1; j++) cout << " ";
      if (s[i - 2] == '/')
        cout << s[i - 3] << s[i - 2] << s[i - 1] << s[i];
      else {
        h++;
        cout << s[i - 2] << s[i - 1] << s[i];
      }
      cout << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
}
