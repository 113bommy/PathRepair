#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <typename T, size_t N>
int SIZE(const T (&t)[N]) {
  return N;
}
template <typename T>
int SIZE(const T &t) {
  return t.size();
}
string to_string(const string s, int x1 = 0, int x2 = 1e9) {
  return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) {
  string t = "";
  for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1);
       __iii__ <= __jjj__; ++__iii__) {
    t += b[__iii__] + '0';
  }
  return '"' + t + '"';
}
template <typename A, typename... C>
string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords);
int l_v_l_v_l = 0, t_a_b_s = 0;
template <typename A, typename B>
string to_string(const pair<A, B> &p) {
  l_v_l_v_l++;
  string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
  l_v_l_v_l--;
  return res;
}
template <typename A, typename... C>
string to_string(const A(&v), int x1, int x2, C... coords) {
  int rnk = rank<A>::value;
  string tab(t_a_b_s, ' ');
  string res = "";
  bool first = true;
  if (l_v_l_v_l == 0) res += '\n';
  res += tab + "[";
  x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
  auto l = begin(v);
  advance(l, x1);
  auto r = l;
  advance(r, (x2 - x1) + (x2 < SIZE(v)));
  for (auto e = l; e != r; e = next(e)) {
    if (!first) {
      res += ", ";
    }
    first = false;
    l_v_l_v_l++;
    if (e != l) {
      if (rnk > 1) {
        res += '\n';
        t_a_b_s = l_v_l_v_l;
      };
    } else {
      t_a_b_s = 0;
    }
    res += to_string(*e, coords...);
    l_v_l_v_l--;
  }
  res += "]";
  if (l_v_l_v_l == 0) res += '\n';
  return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T) {
  cout << to_string(H) << " | ";
  dbgm(T...);
}
const int MOD = (int)1e9 + 7;
string ascii_lowercase = "abcdefghijklmnopqrstuvwxyz";
string ascii_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, m;
int main() {
  cin >> n >> m;
  int ret = 0;
  int diam, col;
  unordered_map<int, unordered_map<int, int>> mk;
  unordered_map<int, unordered_map<int, int>> cp;
  for (int i = 0; i < (n); i++) {
    cin >> col >> diam;
    mk[diam][col] += 1;
  }
  for (int i = 0; i < (m); i++) {
    cin >> col >> diam;
    cp[diam][col] += 1;
  }
  int mksurp;
  int cpsurp;
  int cnt;
  int samediam = 0;
  for (auto x : mk) {
    mksurp = 0;
    cpsurp = 0;
    for (auto y : x.second) {
      cnt = min(y.second, cp[x.first][y.first]);
      ret += cnt;
      samediam += cnt;
      y.second -= cnt;
      cp[x.first][y.first] -= cnt;
      mksurp += y.second;
    }
    for (auto y : cp[x.first]) {
      cpsurp += y.second;
    }
    samediam += min(mksurp, cpsurp);
  }
  printf("%d %d\n", samediam, ret);
  return 0;
}
