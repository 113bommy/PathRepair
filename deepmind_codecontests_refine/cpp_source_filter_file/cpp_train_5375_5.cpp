#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
inline void in(const char *t) {}
template <typename Head, typename... Tail>
inline void in(const char *t, Head &H, Tail &...T) {
  scanf(t, &H);
  in(t, T...);
}
const int OO = 0x3fffffff, N = 1e6 + 7, MOD = 1e9 + 7;
int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
long long lcm(int a, int b) { return (a / gcd(a, b) * 1ll * b); }
void test(int T) {
  int a, b;
  in("%d", a, b);
  ;
  long long l = lcm(a, b);
  a = l / a;
  b = l / b;
  a += (a < b);
  b += (a > b);
  puts(a < b ? "Masha" : a > b ? "Dasha" : "Equal");
}
int main() {
  int tc = 22;
  for (int i = 0; i < tc; ++i) test(i);
}
