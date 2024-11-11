#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vpii = vector<pii>;
using unt = unsigned int;
int popc(unt a) { return __builtin_popcount(a); }
int popc(int a) { return __builtin_popcount(a); }
int popc(ll a) { return __builtin_popcountll(a); }
int popc(ull a) { return __builtin_popcountll(a); }
int ctz(unt a) { return __builtin_ctz(a); }
int ctz(int a) { return __builtin_ctz(a); }
int ctz(ll a) { return __builtin_ctzll(a); }
int ctz(ull a) { return __builtin_ctzll(a); }
int clz(unt a) { return __builtin_clz(a); }
int clz(int a) { return __builtin_clz(a); }
int clz(ll a) { return __builtin_clzll(a); }
int clz(ull a) { return __builtin_clzll(a); }
template <class c, class N>
bool mini(c &o, N h) {
  if (o > h) return o = h, 1;
  return 0;
}
template <class c, class N>
bool maxi(c &o, N h) {
  if (o < h) return o = h, 1;
  return 0;
}
template <class c, class d, class e, class f>
auto operator+(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first + b.first, a.second + b.second)) {
  return {a.first + b.first, a.second + b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator+(c a, pair<d, e> b)
    -> decltype(make_pair(a + b.first, a + b.second)) {
  return {a + b.first, a + b.second};
}
template <class c, class d, class e>
auto operator+(pair<c, d> a, e b)
    -> decltype(make_pair(a.first + b, a.second + b)) {
  return {a.first + b, a.second + b};
}
template <class c, class d, class e>
void operator+=(pair<c, d> &a, e b) {
  a.first += b;
  a.second += b;
}
template <class c, class d, class e, class f>
void operator+=(pair<c, d> &a, pair<e, f> b) {
  a.first += b.first;
  a.second += b.second;
}
template <class c, class d, class e, class f>
auto operator-(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first - b.first, a.second - b.second)) {
  return {a.first - b.first, a.second - b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator-(c a, pair<d, e> b)
    -> decltype(make_pair(a - b.first, a - b.second)) {
  return {a - b.first, a - b.second};
}
template <class c, class d, class e>
auto operator-(pair<c, d> a, e b)
    -> decltype(make_pair(a.first - b, a.second - b)) {
  return {a.first - b, a.second - b};
}
template <class c, class d, class e>
void operator-=(pair<c, d> &a, e b) {
  a.first -= b;
  a.second -= b;
}
template <class c, class d, class e, class f>
void operator-=(pair<c, d> &a, pair<e, f> b) {
  a.first -= b.first;
  a.second -= b.second;
}
template <class c, class d, class e, class f>
auto operator*(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first * b.first, a.second *b.second)) {
  return {a.first * b.first, a.second * b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator*(c a, pair<d, e> b)
    -> decltype(make_pair(a * b.first, a *b.second)) {
  return {a * b.first, a * b.second};
}
template <class c, class d, class e>
auto operator*(pair<c, d> a, e b)
    -> decltype(make_pair(a.first * b, a.second *b)) {
  return {a.first * b, a.second * b};
}
template <class c, class d, class e>
void operator*=(pair<c, d> &a, e b) {
  a.first *= b;
  a.second *= b;
}
template <class c, class d, class e, class f>
void operator*=(pair<c, d> &a, pair<e, f> b) {
  a.first *= b.first;
  a.second *= b.second;
}
template <class c, class d, class e, class f>
auto operator/(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first / b.first, a.second / b.second)) {
  return {a.first / b.first, a.second / b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator/(c a, pair<d, e> b)
    -> decltype(make_pair(a / b.first, a / b.second)) {
  return {a / b.first, a / b.second};
}
template <class c, class d, class e>
auto operator/(pair<c, d> a, e b)
    -> decltype(make_pair(a.first / b, a.second / b)) {
  return {a.first / b, a.second / b};
}
template <class c, class d, class e>
void operator/=(pair<c, d> &a, e b) {
  a.first /= b;
  a.second /= b;
}
template <class c, class d, class e, class f>
void operator/=(pair<c, d> &a, pair<e, f> b) {
  a.first /= b.first;
  a.second /= b.second;
}
template <class c, class d, class e, class f>
auto operator%(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first % b.first, a.second % b.second)) {
  return {a.first % b.first, a.second % b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator%(c a, pair<d, e> b)
    -> decltype(make_pair(a % b.first, a % b.second)) {
  return {a % b.first, a % b.second};
}
template <class c, class d, class e>
auto operator%(pair<c, d> a, e b)
    -> decltype(make_pair(a.first % b, a.second % b)) {
  return {a.first % b, a.second % b};
}
template <class c, class d, class e>
void operator%=(pair<c, d> &a, e b) {
  a.first %= b;
  a.second %= b;
}
template <class c, class d, class e, class f>
void operator%=(pair<c, d> &a, pair<e, f> b) {
  a.first %= b.first;
  a.second %= b.second;
}
template <class c, class d, class e, class f>
auto operator^(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first ^ b.first, a.second ^ b.second)) {
  return {a.first ^ b.first, a.second ^ b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator^(c a, pair<d, e> b)
    -> decltype(make_pair(a ^ b.first, a ^ b.second)) {
  return {a ^ b.first, a ^ b.second};
}
template <class c, class d, class e>
auto operator^(pair<c, d> a, e b)
    -> decltype(make_pair(a.first ^ b, a.second ^ b)) {
  return {a.first ^ b, a.second ^ b};
}
template <class c, class d, class e>
void operator^=(pair<c, d> &a, e b) {
  a.first ^= b;
  a.second ^= b;
}
template <class c, class d, class e, class f>
void operator^=(pair<c, d> &a, pair<e, f> b) {
  a.first ^= b.first;
  a.second ^= b.second;
}
template <class c, class d, class e, class f>
auto operator|(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first | b.first, a.second | b.second)) {
  return {a.first | b.first, a.second | b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator|(c a, pair<d, e> b)
    -> decltype(make_pair(a | b.first, a | b.second)) {
  return {a | b.first, a | b.second};
}
template <class c, class d, class e>
auto operator|(pair<c, d> a, e b)
    -> decltype(make_pair(a.first | b, a.second | b)) {
  return {a.first | b, a.second | b};
}
template <class c, class d, class e>
void operator|=(pair<c, d> &a, e b) {
  a.first |= b;
  a.second |= b;
}
template <class c, class d, class e, class f>
void operator|=(pair<c, d> &a, pair<e, f> b) {
  a.first |= b.first;
  a.second |= b.second;
}
template <class c, class d, class e, class f>
auto operator>>(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first >> b.first, a.second >> b.second)) {
  return {a.first >> b.first, a.second >> b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator>>(c a, pair<d, e> b)
    -> decltype(make_pair(a >> b.first, a >> b.second)) {
  return {a >> b.first, a >> b.second};
}
template <class c, class d, class e>
auto operator>>(pair<c, d> a, e b)
    -> decltype(make_pair(a.first >> b, a.second >> b)) {
  return {a.first >> b, a.second >> b};
}
template <class c, class d, class e>
void operator>>=(pair<c, d> &a, e b) {
  a.first >>= b;
  a.second >>= b;
}
template <class c, class d, class e, class f>
void operator>>=(pair<c, d> &a, pair<e, f> b) {
  a.first >>= b.first;
  a.second >>= b.second;
}
template <class c, class d, class e, class f>
auto operator<<(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first << b.first, a.second << b.second)) {
  return {a.first << b.first, a.second << b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator<<(c a, pair<d, e> b)
    -> decltype(make_pair(a << b.first, a << b.second)) {
  return {a << b.first, a << b.second};
}
template <class c, class d, class e>
auto operator<<(pair<c, d> a, e b)
    -> decltype(make_pair(a.first << b, a.second << b)) {
  return {a.first << b, a.second << b};
}
template <class c, class d, class e>
void operator<<=(pair<c, d> &a, e b) {
  a.first <<= b;
  a.second <<= b;
}
template <class c, class d, class e, class f>
void operator<<=(pair<c, d> &a, pair<e, f> b) {
  a.first <<= b.first;
  a.second <<= b.second;
}
template <class c, class d, class e, class f>
auto operator&(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first & b.first, a.second &b.second)) {
  return {a.first & b.first, a.second & b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator&(c a, pair<d, e> b)
    -> decltype(make_pair(a & b.first, a &b.second)) {
  return {a & b.first, a & b.second};
}
template <class c, class d, class e>
auto operator&(pair<c, d> a, e b)
    -> decltype(make_pair(a.first & b, a.second &b)) {
  return {a.first & b, a.second & b};
}
template <class c, class d, class e>
void operator&=(pair<c, d> &a, e b) {
  a.first &= b;
  a.second &= b;
}
template <class c, class d, class e, class f>
void operator&=(pair<c, d> &a, pair<e, f> b) {
  a.first &= b.first;
  a.second &= b.second;
}
template <class c, class d, class e, class f>
auto operator&&(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first && b.first, a.second &&b.second)) {
  return {a.first && b.first, a.second && b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator&&(c a, pair<d, e> b)
    -> decltype(make_pair(a && b.first, a &&b.second)) {
  return {a && b.first, a && b.second};
}
template <class c, class d, class e>
auto operator&&(pair<c, d> a, e b)
    -> decltype(make_pair(a.first && b, a.second &&b)) {
  return {a.first && b, a.second && b};
}
template <class c, class d, class e, class f>
auto operator||(pair<c, d> a, pair<e, f> b)
    -> decltype(make_pair(a.first || b.first, a.second || b.second)) {
  return {a.first || b.first, a.second || b.second};
}
template <class c, class d, class e,
          class = typename enable_if<!is_base_of<ios_base, c>::value>::type>
auto operator||(c a, pair<d, e> b)
    -> decltype(make_pair(a || b.first, a || b.second)) {
  return {a || b.first, a || b.second};
}
template <class c, class d, class e>
auto operator||(pair<c, d> a, e b)
    -> decltype(make_pair(a.first || b, a.second || b)) {
  return {a.first || b, a.second || b};
}
template <class c, class d>
auto operator-(pair<c, d> e) -> decltype(make_pair(-e.first, -e.second)) {
  return {-e.first, -e.second};
}
template <class c, class d>
auto operator+(pair<c, d> e) -> decltype(make_pair(+e.first, +e.second)) {
  return {+e.first, +e.second};
}
template <class c, class d>
auto operator~(pair<c, d> e) -> decltype(make_pair(~e.first, ~e.second)) {
  return {~e.first, ~e.second};
}
template <class c, class d>
auto operator!(pair<c, d> e) -> decltype(make_pair(!e.first, !e.second)) {
  return {!e.first, !e.second};
}
ull mix(ull x) {
  x += 0x9e3779b97f4a7c15;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x ^ (x >> 31);
}
void fre(string c) {
  freopen((c + ".in").c_str(), "r", stdin);
  freopen((c + ".out").c_str(), "w", stdout);
}
ull str_hash(string x) {
  ull ans = mix(0x15243Ef3abf);
  for (char c : x) ans = mix(ans ^ c);
  return ans;
}
map<string, ull> value;
set<string> used;
struct how_to_get {
  bool input;
  string which;
  ull left, right;
  char op;
  how_to_get(string _w) : input(true), which(_w), left(0), right(0), op(0) {}
  how_to_get(ull _l, char _o, ull _r)
      : input(false), which(), left(_l), right(_r), op(_o) {}
  how_to_get() { assert(false); }
};
map<ull, how_to_get> vars;
ull get_val(string var) {
  auto it = value.find(var);
  if (it == value.end()) {
    ull h = str_hash(var);
    value.insert(make_pair(var, h));
    vars.insert(make_pair(h, how_to_get(var)));
    return h;
  } else
    return it->second;
}
bool is_op(char c) { return c == '^' || c == '$' || c == '&' || c == '#'; }
ull expr_hash(ull left, char c, ull right) {
  ull ans = mix(left);
  ans = mix(ans ^ c);
  ans = mix(ans ^ right);
  return ans;
}
vector<string> out;
char line[1000];
string get_free() {
  static int seed = 123456;
  while (true) {
    string x;
    for (int _ = 0; _ < (int)(4); ++_) {
      seed = mix(seed);
      int v = seed % 52;
      if (v < 26)
        x.push_back('a' + v);
      else
        x.push_back('A' + v - 26);
    }
    if (used.count(x) == 0) {
      used.insert(x);
      return x;
    }
  }
}
map<ull, string> visited;
string dfs(ull x, bool last = false) {
  ;
  auto it = visited.find(x);
  if (it != visited.end()) {
    return it->second;
  }
  how_to_get how = vars[x];
  if (how.input) {
    if (last) {
      if (how.which != "res") out.push_back("res=" + how.which);
      return "res";
    } else {
      return how.which;
    }
  }
  string l = dfs(how.left);
  string r = dfs(how.right);
  string ret = last ? "res" : get_free();
  out.push_back(ret + "=" + l + string(1, how.op) + r);
  visited.insert(make_pair(x, ret));
  ;
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int _ = 0; _ < (int)(n); ++_) {
    scanf("%s", line);
    int equal = -1, op = -1;
    int l = strlen(line);
    for (int i = 0; i < (int)(l); ++i) {
      if (line[i] == '=') equal = i;
      if (is_op(line[i])) op = i;
    }
    if (op != -1) {
      string assigned(line, line + equal), left(line + equal + 1, line + op),
          right(line + op + 1, line + l);
      ull l_val = get_val(left), r_val = get_val(right);
      ull new_hash = expr_hash(l_val, line[op], r_val);
      value[assigned] = new_hash;
      vars.insert(make_pair(new_hash, how_to_get(l_val, line[op], r_val)));
      used.insert(left);
      used.insert(right);
    } else {
      string assigned(line, line + equal), var(line + equal + 1, line + l);
      if (assigned != var) {
        ull val = get_val(var);
        value[assigned] = val;
      }
    }
  };
  ;
  if (value.count("res")) {
    dfs(value["res"], true);
    printf("%d\n", (int)out.size());
    for (string x : out) printf("%s\n", x.c_str());
  } else
    printf("0\n");
}
