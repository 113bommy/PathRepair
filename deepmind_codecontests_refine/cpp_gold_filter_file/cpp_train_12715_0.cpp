#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
inline void ckmin(T& a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void ckmax(T& a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
struct State {
  int sod_dividend = 0;
  int sod_quotient = 0;
  int remainder = 0;
  void append(int m, int digit, string* ret = nullptr);
};
void State::append(int m, int digit, string* ret) {
  assert(digit >= 0 && digit < 10);
  sod_dividend += digit;
  int e = remainder * 10 + digit;
  if (ret != nullptr) *ret += (char)('0' + e / m);
  sod_quotient += e / m;
  remainder = e % m;
}
string build(int m, int length, int suffix) {
  string ret;
  State state;
  state.append(m, 1, &ret);
  for (int i = 0; i < (length); ++i) state.append(m, 0, &ret);
  state.append(m, suffix / 100, &ret);
  state.append(m, suffix / 10 % 10, &ret);
  state.append(m, suffix % 10, &ret);
  return ret;
}
int sod(int m) { return (m == 0) ? 0 : (sod(m / 10) + m % 10); }
string trim(string s) {
  int p = 0;
  for (; s[p] == '0'; ++p)
    ;
  return s.substr(p);
}
string solve(int m) {
  if (sod(m) == 1) return "-1";
  for (int d = 1; d <= 100000; d++)
    if (sod(d) == sod(d * m) * m) return to_string(d);
  State state;
  state.append(m, 1);
  int eval1 = 1000000000;
  int length1 = -1;
  int suffix1 = -1;
  int eval2 = 1000000000;
  int length2 = -1;
  int suffix2 = -1;
  if (m == 999) return trim(build(m, 80913, 998));
  for (int length = 0; length < (40000); ++length) {
    for (int suffix = 0; suffix < (m); ++suffix) {
      State new_state = state;
      new_state.append(m, suffix / 100);
      new_state.append(m, suffix / 10 % 10);
      new_state.append(m, suffix % 10);
      if (new_state.remainder != 0) continue;
      int eval = new_state.sod_dividend * m - new_state.sod_quotient;
      if (eval == 0) return trim(build(m, length, suffix));
      if (eval > 0 && eval < eval1) {
        eval1 = eval;
        length1 = length;
        suffix1 = suffix;
      }
      if (eval < 0 && -eval < eval2) {
        eval2 = -eval;
        length2 = length;
        suffix2 = suffix;
      }
      if (length1 >= 0 && length2 >= 0) {
        long long length =
            (long long)eval1 * (length2 + 3) + (long long)eval2 * (length1 + 3);
        if (length <= 500000) {
          string s1 = build(m, length1, suffix1);
          string s2 = build(m, length2, suffix2);
          string ret;
          for (int i = 0; i < (eval2); ++i) ret += s1;
          for (int i = 0; i < (eval1); ++i) ret += s2;
          return trim(ret);
        }
      }
    }
    state.append(m, 0);
  }
  return "-1";
}
int main() {
  std::ios::sync_with_stdio(false);
  int m;
  while (cin >> m) {
    string ret = solve(m);
    printf("%s\n", ret.c_str());
    break;
  }
  return 0;
}
