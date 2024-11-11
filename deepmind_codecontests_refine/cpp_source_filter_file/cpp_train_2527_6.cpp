#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using ull = unsigned long long;
using int2 = pair<ll, ll>;
using int3 = tuple<ll, ll, ll>;
template <typename A>
string to_string(const A &v);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(const pair<A, B> &p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(const tuple<A, B, C> &p) {
  return "(" + to_string(std::get<0>(p)) + ", " + to_string(std::get<1>(p)) +
         ", " + to_string(std::get<2>(p)) + ")";
}
template <typename A>
string to_string(const A &v) {
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
template <typename T>
void sort(vector<T> &val) {
  sort(val.begin(), val.end());
}
template <typename T>
void reverse(vector<T> &val) {
  reverse(val.begin(), val.end());
}
template <typename T>
void reverse(map<T, T> &val) {
  reverse(val.begin(), val.end());
}
template <typename T>
void sort_b(vector<T> &val) {
  sort(val.begin(), val.end(), greater<T>());
}
template <typename T>
T pair_sum(pair<T, T> &val) {
  return val.first + val.second;
}
template <typename T>
T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <typename T>
T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <typename T>
T mul_mod(T a, T b, T mod) {
  T res = 0;
  a %= mod;
  while (b) {
    if (b & 1) {
      res = (res + a) % mod;
    }
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}
template <typename T>
T fac_mod(T v, T mod) {
  ll res = 1;
  for (ll i = 1; i <= v; i++) {
    res *= i;
    res = res % mod;
  }
  return res;
}
template <typename T>
T pow_mod(T v, T p, T mod) {
  if (p == 1) return v;
  if (p % 2 == 0) {
    T t = pow_mod(v, p / 2, mod);
    return (t * t) % mod;
  } else {
    return (v * pow_mod(v, p - 1, mod)) % mod;
  }
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
class mytask {
 public:
  mytask() {}
  int solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a = 0;
    ll ab = 0;
    ll abc = 0;
    ll mod = 1e9 + 7;
    ll rows = 1;
    for (ll i = 0; i < n; i++) {
      if (s[i] == 'a') a++;
      if (s[i] == 'b') ab += a;
      if (s[i] == 'c') abc += ab;
      if (s[i] == '?') {
        abc *= 3;
        abc += ab;
        ab *= 3;
        ab += a;
        a *= 3;
        a += rows;
        rows *= 3;
      }
      a %= mod;
      ab %= mod;
      abc %= mod;
      rows %= mod;
      ;
      ;
    }
    cout << abc;
    return 0;
  }
};
int main() {
  auto task = mytask();
  task.solve();
  return 0;
}
